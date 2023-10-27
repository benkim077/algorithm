#include <bits/stdc++.h>
using namespace std;

int N, M, mx, _size;
char a[24][24];
int cnt[30], vsted[24][24];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
string input;

void dfs(int y, int x) {
  // cout << a[y][x];
  mx = max(mx, _size);
  vsted[y][x] = 1;
  cnt[a[y][x] - 'A'] = 1;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= N || nx >= M || vsted[ny][nx]) continue;
      if(cnt[a[ny][nx] - 'A'] > 0) continue;
      vsted[ny][nx] = 1;
      cnt[a[ny][nx] - 'A'] = 1;
      _size++;
      dfs(ny, nx);
      vsted[ny][nx] = 0;
      cnt[a[ny][nx] - 'A'] = 0;
      _size--;
  }
}

int main() {
  // cout << 'z' - 'a' + 1;
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> input;
    for(int j = 0; j < M; j++) {
      a[i][j] = input[j];
    }
  }

  _size++;
  dfs(0, 0);
  cout << mx;
}