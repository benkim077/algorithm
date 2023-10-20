#include <bits/stdc++.h>
using namespace std;

int N, M, cnt0, cnt2, mp[8][8], origin[8][8], visited[8][8], mx;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void BFS() {
  queue<pair<int, int>> q;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(mp[i][j] == 2) {
        q.push({i, j});
        visited[i][j] = 1;
      }
    }
  }
  // q.push({iy, ix}); q.push({jy, jx}); q.push({ky, kx});
  // visited[iy][ix] = 1; visited[jy][jx] = 1; visited[ky][kx] = 1;
  while(q.size()) {
    int y; int x;
    tie(y, x) = q.front(); q.pop();
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx]) continue;
        if(mp[ny][nx] == 0) {
          visited[ny][nx] = 1;
          mp[ny][nx] = 2;
          q.push({ny, nx});
          // cnt2++;
        }
      }
    }
  }
}

int main() {
  // 입력 처리
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> origin[i][j];
      // if(mp[i][j] == 0) cnt0++; 
    }
  }
  
  

  // 3칸을 선택(조합)
  for(int i = 0; i < N * M; i++) {
    for(int j = i + 1; j < N * M; j++) {
      for(int k = j + 1; k < N * M; k++) {
        // cnt, mp 초기화
        cnt2 = 0;
        memcpy(mp, origin, sizeof(origin));
        // visited 체크하고, 0만 갈 수 있게 하면 mp 초기화 안해도 ㄱㅊ
        // 아니야 mp 초기화 해야함 mp를 변경하고 BFS를 돌리니까.
        // 아니면 다시 초기화해버리던가 OK
        // visited는 초기화해야함
        memset(visited, 0, sizeof(visited));

        int iy = i / M; int ix = i % M; // N이 아니라 M이었다.
        int jy = j / M; int jx = j % M;
        int ky = k / M; int kx = k % M;
        // 모두 0이면 1로 변환하고 BFS
        if(mp[iy][ix] == 0 && mp[jy][jx] == 0 && mp[ky][kx] == 0) {
          mp[iy][ix] = 1; mp[jy][jx] = 1; mp[ky][kx] = 1;
          
          // for(int i = 0; i < N; i++) {
          //   for(int j = 0; j < M; j++) {
          //     cout << mp[i][j] << ' ';
          //   }
          //   cout << '\n';
          // }
        
          // 이게 아니라, 2에서부터 시작해야지
          BFS();
          // BFS(iy, ix, jy, jx, ky, kx); 

          // 최대값 계산
          // cout << cnt0 - 3 << ' ' << cnt2 << '\n';
          // mp가 바뀌지 않으니까 안전 영역의 수를 셀 수가 없지;
          cnt0 = 0;
          for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
              if(mp[i][j] == 0) cnt0++; 
            }
          }
          mx = max(mx, cnt0);
          // mx = max(mx, (cnt0 - 3) - cnt2);
          mp[iy][ix] = 0; mp[jy][jx] = 0; mp[ky][kx] = 0;
        }
        
      }
    }
  }

  cout << mx;
  return 0;
}