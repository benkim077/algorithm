#include <bits/stdc++.h>
using namespace std;

int H, W, i, j;
int mp[104][104];
string row;
const int dy = 0;
const int dx = 1;

void DFS(int y, int x, int t) {
  int ny = y + dy;
  int nx = x + dx;
  if(ny < 0 || nx < 0 || ny >= H || nx >= W) return;
  // mp를 변경하기 때문에 반드시 출력 전에 -1 이 아님을 체크해야 함
  if(mp[ny][nx] != -1) return;
  mp[ny][nx] = t + 1;
  DFS(ny, nx, t + 1);
}

int main() {
  cin >> H >> W;

  // 맵 초기화
  for(int i = 0; i < H; i++) {
    cin >> row;
    for(int j = 0; j < W; j++) {
      if(row[j] == 'c') {
        mp[i][j] = 0;
      } else {
        mp[i][j] = -1;
      }
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(mp[i][j] != -1) {
        DFS(i, j, 0);
      }
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cout << mp[i][j] << ' ';
    } 
    cout << '\n';
  }
  return 0;
}