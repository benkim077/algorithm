#include <bits/stdc++.h>
using namespace std;
#define prev aaaa

int n, m, l, r, ret, prev, brid;
vector<pair<int, int>> v;


int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        v.push_back({l, r});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        tie(l, r) = v[i];
        if(prev >= l) l = prev;
        if(l >= r) continue;
        // cout << l << ' ' << r << '\n';
        brid = (r - l) / m;
        if((r - l) % m != 0) brid += 1; 
        // cout << brid << "개\n";
        ret += brid; l += m * brid;
        prev = l;
    }
    cout << ret << '\n';
    return 0;
}