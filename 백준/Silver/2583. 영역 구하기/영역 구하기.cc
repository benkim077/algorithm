#include <bits/stdc++.h>
using namespace std;

int M, N, K, lx, ly, rx, ry, cnt;
int mp[104][104];
int visited[104][104];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> ret;

void DFS(int y, int x) {
  if(visited[y][x]) return;
  visited[y][x] = 1;
  cnt++;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
    if(mp[ny][nx]) DFS(ny, nx);
  }
  return;
}

int main() {
  fill(&mp[0][0], &mp[103][104], 1);
  cin >> M >> N >> K;
  // 직사각형 0으로
  for(int i = 0; i < K; i++) {
    cin >> lx >> ly >> rx >> ry;
    for(int y = ly; y < ry; y++) {
      for(int x = lx; x < rx; x++) {
        mp[y][x] = 0;
      }
    }  
  }

  // for(int i = 0; i < M; i++) {
  //   for(int j = 0; j < N; j++) {
  //     cout << mp[i][j];
  //   }
  //   cout << '\n';
  // }

  // 연결된 컴포넌트에서 DFS
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      // DFS 로직에 따라 visited 체크는 필요없지 않을까?
      if(mp[i][j] && !visited[i][j]) {
        DFS(i, j); 
        ret.push_back(cnt);
        // cout << i << ' ' << j << ' ' << cnt << '\n';
        cnt = 0;
      }
    }
  }

  // 오름차순 정렬 후 출력하기
  sort(ret.begin(), ret.end());
  cout << ret.size() << '\n';
  for(int i = 0; i < ret.size(); i++) {
    cout << ret[i] << ' ';
  }

  return 0;
}