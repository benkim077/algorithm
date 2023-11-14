#include <bits/stdc++.h>
using namespace std;

long long n, ret, l, r, sz;
long long a[100004], cnt[100004];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    l = 0; r = 0; sz = 1; ret = 1, cnt[a[0]]++;
    for(int i = 1; i < n; i++) {
        // cout << ret << '\n';
        while(cnt[a[i]]) {
            cnt[a[l]]--; sz--; l++;
        }
        r++; sz++; ret += sz; cnt[a[i]]++;
        // cout << sz << '\n';
    }

    cout << ret << '\n';
    return 0;
}