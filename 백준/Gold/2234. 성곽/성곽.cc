#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, mx = 0, ret = 0;
int a[54][54], vsted[54][54];
int area[54];
const int dy[] = {0, -1, 0, 1}; // 좌상우하
const int dx[] = {-1, 0, 1, 0};
map<int, vector<pair<int, int>>> adj;


int dfs(int y, int x) {
    int _ret = 1;
    vsted[y][x] = cnt;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || vsted[ny][nx]) continue;
        if(a[y][x] & (1 << i)) {
            adj[cnt].push_back({ny, nx});
            continue;
        }
        vsted[ny][nx] = cnt;
        _ret += dfs(ny, nx);
    }
    return _ret;
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < n;i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vsted[i][j]) continue;
            cnt++;
            vsted[i][j] = cnt;
            area[cnt] = dfs(i, j);
        }
    }
    cout << cnt << '\n';
    for(int i = 1; i < cnt + 1; i++) mx = max(mx, area[i]); 
    cout << mx << '\n'; 

    for(int i = 1; i < cnt + 1; i++) {
        for(auto p : adj[i]) {
            int y, x; tie(y, x) = p;
            if(vsted[y][x] == i) continue;
            ret = max(ret, area[vsted[y][x]] + area[i]);

        }
    }
    cout << ret << '\n';
    return 0;
}