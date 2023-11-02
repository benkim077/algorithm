#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
string name, state;
map<string, bool> mp;

bool cmp(pair<string, bool> a, pair<string, bool> b) {
    return a.first > b.first;
}

int main() {
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name >> state;
        if(state == "enter") mp[name] = 1;
        else mp.erase(name);
    }

    vector<pair<string, bool>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);
    for(auto p : v) {
        if(p.second == 1) cout << p.first << '\n';
    }
    return 0;
}