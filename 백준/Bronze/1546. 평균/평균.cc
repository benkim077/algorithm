#include <bits/stdc++.h>
using namespace std;

int n;
double a[1004], avg, mx = 0;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    for(int i = 0; i < n; i++) {
        a[i] = a[i] / mx * 100;
    }
    cout << (double)accumulate(a, a + n, (double)0) / n;
}