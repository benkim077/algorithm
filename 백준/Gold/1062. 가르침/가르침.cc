#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
int a[54];

void go(int idx, int kcnt, int mask) {
    if(kcnt > k) return;
    if(idx == 26) {
        int _cnt = 0;
        for(int i = 0; i < n; i++) {
            if((mask & a[i]) == a[i]) _cnt++;
        }
        ret = max(ret, _cnt);
        return;
    }

    if(idx == 'a' - 'a' || 
        idx == 'c' - 'a' || 
        idx == 'n' - 'a' || 
        idx == 'i' - 'a' || 
        idx == 't' - 'a') {
        go(idx + 1, kcnt + 1, mask | (1 << idx));
    } else {
        go(idx + 1, kcnt + 1, mask | (1 << idx));
        go(idx + 1, kcnt, mask);
    }
}

int main() {
    cin >> n >> k;
    string temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        for(int j = 0; j < temp.size(); j++) {
            a[i] |= (1 << (temp[j] - 'a'));
        }
    }

    go(0, 0, 0);
    cout << ret << '\n';
    return 0;
}