#include <bits/stdc++.h>
using namespace std;

int n, mn = 987654321;
int a[24][24];
string s;

int solve() {
    int ret = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0; // T의 갯수를 센다.
        for(int j = 0; j < n; j++) {
            if(!a[j][i]) cnt++;
        } 
        if(cnt > n - cnt) ret += n - cnt;
        else ret += cnt;
    }
    return ret;
}

void go(int idx) {
    if(idx == n) {
        mn = min(mn, solve());
        return;
    }

    go(idx + 1);
    for(int j = 0; j < n; j++) {
        a[idx][j] = a[idx][j] ? 0 : 1;
    }
    go(idx + 1);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            if(s[j] == 'H') a[i][j] = 1;
        }
    }

    go(0);
    cout << mn << '\n';
    return 0;
}