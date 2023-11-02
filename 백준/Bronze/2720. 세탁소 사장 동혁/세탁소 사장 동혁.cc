#include <bits/stdc++.h>
using namespace std;

int t, c;
const int pay[] = {25, 10, 5, 1};

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> c;
        for(int a : pay) {
            cout << c / a << ' ';
            c %= a;
        }
        cout << '\n';
    }
    return 0;
}