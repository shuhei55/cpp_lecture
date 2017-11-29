#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    int max = 0;
    for (int i = 1; i < n - 2; i++) {
        if (max < (a.at(n - 1) + a.at(n - 2)) / (a.at(i) - a.at(i - 1))) {
            max = (a.at(n - 1) + a.at(n - 2)) / (a.at(i) - a.at(i - 1));
        }
    }
    if (max < (a.at(n - 1) + a.at(n - 4)) / (a.at(n - 2) - a.at(n - 3))) {
        max = (a.at(n - 1) + a.at(n - 4)) / (a.at(n - 2) - a.at(n - 3));
    } 
    if (max < (a.at(n - 3) + a.at(n - 4)) / (a.at(n - 1) - a.at(n - 2))) {
        max = (a.at(n - 3) + a.at(n - 4)) / (a.at(n - 1) - a.at(n - 1));
    }
    cout << max << endl;
    return 0;

}
