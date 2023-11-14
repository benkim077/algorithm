#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int r, c, t, a[54][54], b[54][54], ret;
pair<int, int> air1, air2;
queue<pair<int, int>> q;

void BFS() {
    memset(b, 0, sizeof(b));
    int y, x, dcnt;
    while(q.size()) { 
        dcnt = 0; 
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(a[ny][nx] == -1) continue;
            dcnt++;
            b[ny][nx] += a[y][x] / 5;
        }
        b[y][x] += a[y][x] - (a[y][x] / 5) * dcnt;
    }
    memcpy(a, b, sizeof(a));
    a[air1.first][air1.second] = -1; a[air2.first][air2.second] = -1;
}


void dfs(int y, int x, vector<int> &dy, vector<int> &dx, int d, int v, int sy, int sx) {
    // cout << y << ' ' << x << '\n';
    int ny = y + dy[d]; int nx = x + dx[d];
    if(sy == air1.first) {
        if(ny < 0 || nx < 0 || ny >= sy + 1 || nx >= c) { // 아래 , 위 에 따라 달라짐
            dfs(y, x, dy, dx, (d + 1) % 4, v, sy, sx); 
            return;
        }
    }
    else {
        if(ny < sy || nx < 0 || ny >= r || nx >= c) {
            dfs(y, x, dy, dx, (d + 1) % 4, v, sy, sx);
            return;
        }
    }
    
    int temp = a[y][x] == -1 ? 0 : a[y][x];
    if(v == -1) a[y][x] = -1;
    else a[y][x] = v;
    if(ny == sy && nx == sx) return; 
    dfs(ny, nx, dy, dx, d, temp, sy, sx);
}

int main() {
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            if(a[i][j] == -1) {
                air2 = {i, j};
                air1 = {i - 1, j}; 
            }
        }
    }

    for(int i = 0; i < t; i++) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(a[i][j] > 0) q.push({i, j});
            }
        }
        BFS();
        vector<int> dy_ = {0, -1, 0, 1};
        vector<int> dx_ = {1, 0, -1, 0};
        dfs(air1.first, air1.second, dy_, dx_, 0, -1, air1.first, air1.second);
        dy_ = {0, 1, 0, -1};
        dx_ = {1, 0, -1, 0};
        // cout << '\n';
        dfs(air2.first, air2.second, dy_, dx_, 0, -1, air2.first, air2.second);
        // for(int i = 0; i < r; i++) {
        //     for(int j = 0; j < c; j++) {
        //         cout << a[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a[i][j] > 0) {
                ret += a[i][j];          
            }
        }
    }
    cout << ret << '\n';
    return 0;
}
