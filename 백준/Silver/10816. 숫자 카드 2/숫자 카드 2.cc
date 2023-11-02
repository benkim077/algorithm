#include <bits/stdc++.h>
using namespace std;

int n, m;
int temp;
map<int, int> mp;

int main() {
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        mp[temp]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        cout << mp[temp] << ' ';
    }
    return 0;
}