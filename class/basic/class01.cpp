#include <iostream>
#include <string>

using namespace std;

struct Person
{
    void introduce()
    {
        cout << "名前は" << name << endl;
        cout << age << endl;
    }
    void reachBirthday()
    {
        age++;
    }
    string name;
    int age;
    double height, weight;
};

int main() 
{
    Person one;
    one.name = "太郎";
    one.age = 18;
    one.height = 1.711;
    one.weight = 62.41;
    one.introduce();
    one.reachBirthday();
    one.introduce();
}
