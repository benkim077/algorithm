#include <bits/stdc++.h>
using namespace std;

int n, mx = -1000001, mn = 1000001, a;

int main() {
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        mx = max(mx, a);
        mn = min(mn, a);
    }
    cout << mn << ' ' << mx;
}