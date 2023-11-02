#include <bits/stdc++.h>
using namespace std;

int n, m;
int temp;
map<int, bool> mp;

int main() {
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        mp[temp] = 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        if(mp[temp] == 1) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    return 0;
}