#include <bits/stdc++.h>
using namespace std;

int h, m;

int main() {
    cin >> h >> m;
    m += h * 60;
    m -= 45;
    if(m < 0) m += 60 * 24;
    h = m / 60;
    m = m % 60;
    cout << h << ' ' << m;
}