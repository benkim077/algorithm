#include <bits/stdc++.h>
using namespace std;
#define prev aaaa
typedef long long ll;

ll n, k, m, v, b, ret;
vector<pair<ll, ll>> jewel;
vector<ll> bag;
priority_queue<ll> pq;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> m >> v;
        jewel.push_back({m, v});
    }
    for(int i = 0; i < k; i++) {
        cin >> b;
        bag.push_back(b);
    }
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    int j = 0;
    for(int i = 0; i < k; i++) {
        while(j < n && bag[i] >= jewel[j].first) pq.push(jewel[j++].second);
        if(pq.size()) {ret += pq.top(); pq.pop();}


        // for(j = prev; j < n; j++) {
        //     if(b >= jewel[j].first) {
        //         pq.push(jewel[j].second);
        //     }
        //     else {
        //         prev = j;
        //         if(pq.size()) ret += pq.top(); pq.pop();
        //         break;
        //     }
        // }
        // if(j == n && pq.size()) {ret += pq.top(); pq.pop(); }
    }

    cout << ret << '\n';
    return 0;
}
