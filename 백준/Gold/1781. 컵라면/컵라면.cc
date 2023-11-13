#include <bits/stdc++.h>
using namespace std;

int n, d, c, ret;
vector<pair<int, int>> v; // 데드라인, 컵라면 수
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> d >> c;
        v.push_back({d, c});
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        tie(d, c) = v[i];
        pq.push(c);
        while(pq.size() > d) pq.pop();
    }
    while(pq.size()) {ret += pq.top(); pq.pop(); }
    cout << ret << '\n';
    return 0;
}