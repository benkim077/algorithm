#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int M, H, N, mn = INF;
int mp[34][14];
bool flag;

// 0행부터 시작해서 N행에서 열을 출력
int move(int y, int x) {
  int start = x;
  while(y < N) {
    if(mp[y][x] == 0) {
      y++;
    }
    if(mp[y][x] == 1) {
      y++; x++;
    }
    if(mp[y][x] == -1) {
      y++; x--;
    }
  }
  if(x == start) return true;
  return false;
}

// 게임 진행
bool game() {
  bool _ret = true;
  for(int i = 0; i < M; i++) {
    if(!move(0, i)) {
      _ret = false;
      break;
    }
  }
  return _ret;
}

// 줄을 하나씩 추가하면서 게임을 돌린다.
// 완전탐색에서 int 형 함수를 사용하기 힘들다?
void go(int n, int here) {
  if(n > 3 || n >= mn) return;
  if(game()) {
    mn = min(mn, n);
    return;
  }
  for(int i = here; i < N; i++) {
    for(int j = 0; j < M - 1; j++) {
      if(mp[i][j] != 0 || mp[i][j + 1] != 0) continue;
      mp[i][j] = 1; mp[i][j + 1] = -1;
      go(n + 1, i); 
      mp[i][j] = 0; mp[i][j + 1] = 0;
    }
  }
}

int main() {
  cin >> M >> H >> N;
  for(int i = 0; i < H; i++) {
    int y, x;
    cin >> y >> x;
    y--; x--;
    mp[y][x] = 1;
    mp[y][x + 1] = -1;
  }

  go(0, 0);
  if(mn == INF) cout << -1;
  else cout << mn;
  
}