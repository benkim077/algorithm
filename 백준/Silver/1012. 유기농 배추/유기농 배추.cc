#include <bits/stdc++.h>
using namespace std;

int mp[54][54];
int visited[54][54];
int cnt;
int T, M, N, K, X, Y;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void BFS(int y, int x) {
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push({y, x});
  while(q.size()) {
    tie(y, x) = q.front(); q.pop();
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if(!mp[ny][nx]) continue;
      if(!visited[ny][nx]) {
        visited[ny][nx] = 1;
        q.push({ny, nx});
      }
    }
  }

  return;
}

int main() {
  cin >> T;  
  for(int tc = 0; tc < T; tc++) {
    cnt = 0;
    fill(&mp[0][0], &mp[53][54], 0);
    fill(&visited[0][0], &visited[53][54], 0);
    
    cin >> M >> N >> K;
    for(int k = 0; k < K; k++) {
      cin >> X >> Y;
      mp[Y][X] = 1;
    }
    
    for(int n = 0; n < N; n++) {
      for(int m = 0; m < M; m++) {
        if(mp[n][m] && !visited[n][m]) {
          BFS(n, m);
          cnt++;
        }
      }
    }

    cout << cnt << '\n';
  }
  return 0;
}

