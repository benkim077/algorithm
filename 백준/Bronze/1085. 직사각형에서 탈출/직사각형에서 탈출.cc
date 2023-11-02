#include <bits/stdc++.h>
using namespace std;

int x, y, w, h, mn = 1000;

int main() {
    cin >> x >> y >> w >> h;
    int t1 = min(abs(x - 0), abs(x - w));
    int t2 = min(abs(y - 0), abs(y - h));
    mn = min(t1, t2);
    cout << mn;
    return 0;
}