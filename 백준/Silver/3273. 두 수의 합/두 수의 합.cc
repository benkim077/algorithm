#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x, l, r, a[100004];
ll ret;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;

    sort(a, a + n);
    l = 0, r = n - 1;
    while(l < r) {
        if(a[l] + a[r] == x) {
            // cout << l << ' ' << r << '\n';
            ret++;
            r--;
        }
        else if(a[l] + a[r] < x) l++;
        else if(a[l] + a[r] > x) r--;
    }
    cout << ret << '\n';
    return 0;
}
