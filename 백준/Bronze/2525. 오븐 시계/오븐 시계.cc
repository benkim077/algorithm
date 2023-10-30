#include <bits/stdc++.h>
using namespace std;

int h, m, t;

int main() {
    cin >> h >> m;
    cin >> t;
    m += h * 60;
    m += t;
    h = m / 60;
    m = m % 60;
    if(h > 23) h -= 24;
    cout << h << ' ' << m;
}