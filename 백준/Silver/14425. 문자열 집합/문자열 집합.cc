#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
string input;
map<string, bool> mp;

int main() {
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> input;
        mp[input] = 1;
    }
    for(int i = 0; i < m; i++) {
        cin >> input;
        if(mp[input] == 1) cnt++;
    }
    cout << cnt;
    return 0;
}