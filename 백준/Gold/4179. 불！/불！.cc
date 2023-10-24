#include <bits/stdc++.h>
using namespace std;

int N, M, yJ, xJ, t;
char mp[1004][1004];
int vstedJ[1004][1004], vstedF[1004][1004]; // 이건 내가 더 신경쓰는 수밖에 없다.
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
string input;

void BFS() {
  queue<tuple<int, int, bool>> q; // y, x, isJH
  q.push({yJ, xJ, true});
  vstedJ[yJ][xJ] = 1;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(mp[i][j] == 'F') {
        q.push({i, j, false});
        vstedF[i][j] = 1;
      }
    }
  }

  while(q.size()) {
    int y, x; bool isJH;
    tie(y, x, isJH) = q.front(); q.pop();
    // cout << y << x << '\n';
    if(isJH) {
      // 이미 화염이 왔으면 현재 J는 종료
      if(mp[y][x] == 'F') continue;
      // 여기서 맨 끝인지 확인해야지
      if(y == 0 || y == N - 1 || x == 0 || x == M - 1) {
        t = vstedJ[y][x];
        break;
      }
      for(int i = 0; i < 4; i++) {
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(vstedJ[ny][nx]) continue;
        if(mp[ny][nx] != '.') continue;
        vstedJ[ny][nx] = vstedJ[y][x] + 1;
        mp[ny][nx] = 'J';
        q.push({ny, nx, true});
      }
    } else {
      for(int i = 0; i < 4; i++) {
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(vstedF[ny][nx]) continue;
        if(mp[ny][nx] == '#') continue;
        vstedF[ny][nx] = 1;
        mp[ny][nx] = 'F';
        q.push({ny, nx, false});
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> input; 
    for(int j = 0; j < M; j++) {
      mp[i][j] = input[j];
      // 문장이 2개인데, 중괄호를 안쳤구나..
      if(mp[i][j] == 'J') { 
        yJ = i; 
        xJ = j;
      }
    }
    // cout << '\n';
  }
  // cout << yJ << xJ << '\n';

  BFS();
  if(t) cout << t;
  else cout << "IMPOSSIBLE";
  return 0;
}