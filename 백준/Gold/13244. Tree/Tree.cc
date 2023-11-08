#include <bits/stdc++.h>
using namespace std;
#define prev aaaa

int t, n, m, a, b, cnt;
vector<int> adj[1004];
int vsted[1004];

void dfs(int here) {
    vsted[here] = 1;
    for(int there : adj[here]) {
        if(vsted[there]) continue;
        dfs(there);
    }
    return;
}

int main() {
    cin >> t;
    while(t--) {
        for(int i = 0; i < 1004; i++) adj[i].clear();
        fill(vsted, vsted + 1004, 0);
        cnt = 0;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i = 1; i < n + 1; i++) {
            if(!vsted[i]) {
                dfs(i);
                cnt++;
            }
        }

        if(m == n - 1 && cnt == 1) cout << "tree" << '\n';
        else cout << "graph" << '\n';
    }
    return 0;
}