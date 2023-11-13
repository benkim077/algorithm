#include <bits/stdc++.h>
using namespace std;
#define prev aaaa

int n, s, e, prev, ret;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second; // 종료시간 오름차순
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) {
        tie(s, e) = v[i];
        if(s < prev) continue;
        else {
            // cout << s << ' ' << e << '\n';
            ret++;
            prev = e;
        }
    }
    cout << ret << '\n';
    return 0;
}