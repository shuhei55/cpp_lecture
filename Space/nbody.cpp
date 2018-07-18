#include <cstdio>
#include <cstdlib>
#include <cmath> 
#include <unistd.h>
#include <cpgplot.h>
#include "ss_time.h"
#include "simd.h"

struct Particle {
    double mass;
    double posx;
    double posy;
    double posz;
    double velx;
    double vely;
    double velz;
    double accx;
    double accy;
    double accz;
    double potg;
    double velx2;
    double vely2;
    double velz2;
};

inline double generateRandomNumber() {
    return rand() / (double)RAND_MAX;
}

void generateInitialCondition(const int n,
                              Particle * ptcl) {
    for(int i = 0; i < n; i++) {
        ptcl[i].mass = 1.0 / n;
        double r, vr;
        do {
            double x = generateRandomNumber() * 2 - 1;
            double y = generateRandomNumber() * 2 - 1;
            double z = generateRandomNumber() * 2 - 1;            
            r = sqrt(x*x+y*y+z*z);
            ptcl[i].posx = x;
            ptcl[i].posy = y;
            ptcl[i].posz = z;
        } while (r > 1);
        do {
            double vx = generateRandomNumber() * 0.25 - 0.125;
            double vy = generateRandomNumber() * 0.25 - 0.125;
            double vz = generateRandomNumber() * 0.25 - 0.125;
            vr = sqrt(vx*vx+vy*vy+vz*vz);
            ptcl[i].velx = vx;
            ptcl[i].vely = vy;
            ptcl[i].velz = vz;
        } while (vr > 0.125);
    }
    return;
}


/*
void calcGravity(const int n,
                 const double eps2,
                 Particle * ptcl) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            double dx,dy,dz,r2;
            dx = ptcl[j].posx - ptcl[i].posx;
            dy = ptcl[j].posy - ptcl[i].posy;
            dz = ptcl[j].posz - ptcl[i].posz;
            r2 = dx*dx+dy*dy+dz*dz+eps2;
            ptcl[i].potg = ptcl[i].potg + (-G * ptcl[j].mass/sqrt(r2));
        }
        ptcl[i].potg += G * ptcl[i].mass / sqrt(eps2);
    }
}
*/

/*
void calcGravity(const int n,
                 const double eps2,
                 Particle * ptcl) {
    for(int i = 0; i < n; i++) {
        ptcl[i].accx = 0;
        ptcl[i].accy = 0;
        ptcl[i].accz = 0;
        ptcl[i].potg = 0;
        for(int j = 0; j < n; j++) {
            double dx,dy,dz,r2;
            dx = ptcl[j].posx - ptcl[i].posx;
            dy = ptcl[j].posy - ptcl[i].posy;
            dz = ptcl[j].posz - ptcl[i].posz;
            r2 = dx*dx+dy*dy+dz*dz+eps2;
            ptcl[i].accx += ptcl[j].mass * dx / sqrt(pow(r2,3));
            ptcl[i].accy += ptcl[j].mass * dy / sqrt(pow(r2,3));
            ptcl[i].accz += ptcl[j].mass * dz / sqrt(pow(r2,3));
            ptcl[i].potg = ptcl[i].potg + (-1.0 * ptcl[j].mass/sqrt(r2));
        }
        ptcl[i].potg += ptcl[i].mass / sqrt(eps2);
    }
}
*/


void calcGravity(const int n,
                 const double eps2,
                 Particle * ptcl) {
    double seps2 = 1.0/sqrt(eps2);
    for(int i = 0; i < n; i += 4) {
        v4df iaccx(0.0);
        v4df iaccy(0.0);
        v4df iaccz(0.0);
        v4df ipotg(0.0);
        v4df iposx(ptcl[i].posx, ptcl[i+1].posx, ptcl[i+2].posx, ptcl[i+3].posx);
        v4df iposy(ptcl[i].posy, ptcl[i+1].posy, ptcl[i+2].posy, ptcl[i+3].posy);
        v4df iposz(ptcl[i].posz, ptcl[i+1].posz, ptcl[i+2].posz, ptcl[i+3].posz);
        v4df imass(ptcl[i].mass, ptcl[i+1].mass, ptcl[i+2].mass, ptcl[i+3].mass);
        for(int j = 0; j < n; j++) {
            v4df dx, dy, dz, r2, rt, rt3;
            dx = v4df(ptcl[j].posx) - iposx;
            dy = v4df(ptcl[j].posy) - iposy;
            dz = v4df(ptcl[j].posz) - iposz;
            r2 = dx * dx + dy * dy + dz * dz + v4df(eps2);
            rt = v4df::rsqrt_1st(r2);
            rt3 = rt * rt * rt;
            iaccx += v4df(ptcl[j].mass) * dx * rt3;
            iaccy += v4df(ptcl[j].mass) * dy * rt3;
            iaccz += v4df(ptcl[j].mass) * dz * rt3;
            ipotg -= v4df(ptcl[j].mass) * rt;
        }
        ipotg += imass * v4df(seps2);
        double bufferx[4], buffery[4], bufferz[4],buffer[4];
        ipotg.store(buffer);
        iaccx.store(bufferx);
        iaccy.store(buffery);
        iaccz.store(bufferz);
        for(int j = 0; j < 4; j++) {
            ptcl[i + j].potg = buffer[j];
            ptcl[i + j].accx = bufferx[j];
            ptcl[i + j].accy = buffery[j];
            ptcl[i + j].accz = bufferz[j];
        }
    }
}



double calcTotalEnergy(const int n,
                       Particle * ptcl) {
    double etot = 0.0;
    for(int i = 0; i < n; i++) {
        etot += 0.5 * ptcl[i].mass
            * (ptcl[i].potg
               + ptcl[i].velx * ptcl[i].velx
               + ptcl[i].vely * ptcl[i].vely
               + ptcl[i].velz * ptcl[i].velz);
    }
    return etot;
}

void predict(const int n,
             const double dt,
             Particle * ptcl) {
    for(int i = 0; i < n; i++) {
        ptcl[i].posx = ptcl[i].posx + ptcl[i].velx * dt + ptcl[i].accx * dt * dt / 2;
        ptcl[i].posy = ptcl[i].posy + ptcl[i].vely * dt + ptcl[i].accy * dt * dt / 2;
        ptcl[i].posz = ptcl[i].posz + ptcl[i].velz * dt + ptcl[i].accz * dt * dt / 2;

        ptcl[i].velx2 = ptcl[i].velx + ptcl[i].accx * dt /2;
        ptcl[i].vely2 = ptcl[i].vely + ptcl[i].accy * dt /2;
        ptcl[i].velz2 = ptcl[i].velz + ptcl[i].accz * dt /2;
    }
}

void correct(const int n,
             const double dt,
             Particle * ptcl) {
    for(int i = 0; i < n; i++) {
        ptcl[i].velx = ptcl[i].velx2 + (1.0/2.0) * ptcl[i].accx * dt;
        ptcl[i].vely = ptcl[i].vely2 + (1.0/2.0) * ptcl[i].accy * dt;
        ptcl[i].velz = ptcl[i].velz2 + (1.0/2.0) * ptcl[i].accz * dt;
    }
}

void displayParticle(const int n,
                     Particle * ptcl) {
    float x[n], y[n];
    
    for(int i = 0; i < n; i++) {
        x[i] = ptcl[i].posx;
        y[i] = ptcl[i].posy;
    }

    cpgbbuf();
    cpgeras();
    cpgbox("bcnst", 0.0, 0, "bcnst", 0.0, 0);
    cpgebuf();
    cpglab("x", "y", "Cold collapse");
    cpgpt(n, x, y, 18);
    cpgebuf();
    usleep(2e4);
}

int main(int argc,
         char ** argv) {
    const int    n     = 1024;
    const double eps2  = (4. / n) * (4. / n);
    const double tend  = 2.0;
    static Particle ptcl[n];

    double t     = 0.0;
    double tout  = 0.0;
    double dtout = 1.0 / 128.0;
    double etot0, etot;
    int    nstep = 0;
    double wt_force = 0.0;
    double wt_other = 0.0;
    
    generateInitialCondition(n, ptcl);

    /*for (int i = 0; i < n; i++) {    //初期化確認
        printf("%f %f %f %f %f %f\n", 
                ptcl[i].posx, ptcl[i].posy,ptcl[i].posz,
                ptcl[i].velx,ptcl[i].vely,ptcl[i].velz);
    }*/
    
    calcGravity(n, eps2, ptcl);

    /*for (int i = 0; i< n;i++) {    //重力加速度と位置が比例
        printf("%f %f\n",
                sqrt(ptcl[i].posx * ptcl[i].posx +
                     ptcl[i].posy * ptcl[i].posy +
                     ptcl[i].posz * ptcl[i].posz),
                sqrt(ptcl[i].accx * ptcl[i].accx + 
                     ptcl[i].accy * ptcl[i].accy + 
                     ptcl[i].accz * ptcl[i].accz));
    }*/

/*
    double ew = 0.0;    //エネルギー
    for (int i = 0; i < n ; i++){
        ew = ew + 0.5 * ptcl[i].mass * ptcl[i].potg;
    }
    printf("%f\n",ew);
*/
    //exit(0);

    if(argc != 2) {
        fprintf(stderr, "%s <dtinv>\n", argv[0]);
        exit(0);
    }

    double dt    = 1.0 / atof(argv[1]);

/*
    if(cpgopen("?") < 1) {
        return 1;
    }
    cpgenv(-2.0, +2.0, -2.0, +2.0, 1, 0);
*/
    while(t < tend) {
        etot  = calcTotalEnergy(n, ptcl);
        if(t == 0.0) {
            etot0 = etot;
        }    
        if(t >= tout) {
            //displayParticle(n, ptcl);
            printf("%+e %8d %+e %+e\n", t, nstep, etot, (etot - etot0) / etot0);
            tout += dtout;
        }

        double wt1 = getWallclockTime();
        predict(n, dt, ptcl);
        double wt2 = getWallclockTime();
        wt_other +=  wt2 - wt1;
        calcGravity(n, eps2, ptcl);
        double wt3 = getWallclockTime();
        wt_force +=  wt3 - wt2;
        correct(n, dt, ptcl);
        double wt4 = getWallclockTime();
        wt_other +=  wt4 - wt3;

        t += dt;
        nstep++;
    }

    printf("WT force: %+e\n", wt_force / (double)nstep);
    printf("WT other: %+e\n", wt_other / (double)nstep);
    printf("%+e %8d %+e %+e\n", t, nstep, etot, (etot - etot0) / etot0);

    //cpgclos();

    return 0;
}
