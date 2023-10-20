#include <bits/stdc++.h>
using namespace std;

int Y, X, a[104][104], visited[104][104], latest, cnt;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void dfs(int y, int x) {
  visited[y][x] = 1;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= Y || nx >= X) continue;
    if(visited[ny][nx]) continue;
    if(a[ny][nx] == 1) {
      // 여기도 해줬어야했네, 전부 다 큐에 들어가버림
      visited[ny][nx] = 1; 
      q.push({ny, nx});
    }
    if(a[ny][nx] == 0) {
      dfs(ny, nx);
    }
  }
}

int main() {
  cin >> Y >> X;
  for(int i = 0; i < Y; i++) {
    for(int j = 0; j < X; j++) { // 이것 때문에 ..ㅠ
      cin >> a[i][j];
    }
  }

  while(true) {
    memset(visited, 0, sizeof(visited));
    dfs(0, 0);
    latest++;

    cnt = 0;
    while(q.size()) {
      int y, x;
      tie(y, x) = q.front(); q.pop();
      a[y][x] = 0;
      cnt++;
    }
    
    bool done = true;
    for(int i = 0; i < Y; i++) {
      for(int j = 0; j < X; j++) {
        if(a[i][j] == 1) done = false;
      }
    }
    if(done) break;
  }

  cout << latest << '\n' << cnt << '\n';
  return 0;
}