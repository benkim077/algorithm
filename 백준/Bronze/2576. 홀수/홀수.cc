#include <bits/stdc++.h>
using namespace std;

const int n = 7;
int a[n], sum, mn = 100;

int main() {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if(a[i] & 1) {
            mn = min(mn, a[i]);
            sum += a[i];
        }
    }
    if(!sum) {
        cout << -1 << '\n';
        return 0;
    }
    cout << sum << '\n';
    cout << mn << '\n';
    return 0;
}
