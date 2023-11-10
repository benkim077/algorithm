#include <bits/stdc++.h>
using namespace std;

int n;
vector<double> v;

int main() {
    cin >> n;
    double temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        // v.push_back(temp);
    }

    sort(v.begin(), v.end());
    // cout.setf(ios::fixed);
    cout << fixed;
    cout.precision(3);
    for(int i = 0; i < 7; i++) {
        cout << v[i] << '\n';
        // cout << (double)(v[i] / 1000) << '\n';
    }
    return 0;
}