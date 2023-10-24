#include <bits/stdc++.h>
using namespace std;

int n, m, mx, visited[54][54];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char a[54][54];
string temp;

int BFS(int y, int x) {
  int last;
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push({y, x});
  while(q.size()) {
    int y; int x;
    tie(y, x) = q.front(); q.pop();
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if(visited[ny][nx]) continue;
      if(a[ny][nx] == 'L') {
        visited[ny][nx] = visited[y][x] + 1;
        last = visited[ny][nx];
        q.push({ny, nx});
      }
    }
  }
  // cout << y << x << ":" << last - 1 << '\n';
  return last - 1;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    for(int j = 0; j < m; j++) {
      a[i][j] = temp[j];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] == 'L') {
        memset(visited, 0, sizeof(visited));
        int dist = BFS(i, j);
        mx = max(mx, dist);
      }
    }
  }
  cout << mx;
}