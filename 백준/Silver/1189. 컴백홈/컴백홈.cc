#include <bits/stdc++.h>
using namespace std;

int N, M, K;
char mp[10][10], vsted[10][10];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
string input;

int go(int y, int x, int cnt) {
  int _ret = 0;
  if(y == 0 && x == M - 1) { 
    if(cnt == K) {
      return 1;
    } else {
      return 0;
    }
  }
  
  vsted[y][x] = 1;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= N || nx >= M || vsted[ny][nx]) continue;
    if(mp[ny][nx] == 'T') continue;
    vsted[ny][nx] = 1;
    _ret += go(ny, nx, cnt + 1);
    vsted[ny][nx] = 0;
  }
  return _ret;
} 

int main() {
  cin >> N >> M >> K;
  for(int i = 0; i < N; i++) {
    cin >> input;
    for(int j = 0; j < M; j++) {
      mp[i][j] = input[j];
    }
  }

  if(mp[N - 1][0] == 'T') cout << 0;
  else cout << go(N - 1, 0, 1);
}