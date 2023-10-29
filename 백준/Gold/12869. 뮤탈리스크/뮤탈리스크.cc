#include <bits/stdc++.h> 
using namespace std;

int N;
int a[3], vsted[64][64][64];
const int b[6][3] = {
  {9, 3, 1}, 
  {9, 1, 3}, 
  {3, 9, 1}, 
  {3, 1, 9}, 
  {1, 9, 3}, 
  {1, 3, 9},
};
struct A {
  int x, y, z;
};

int BFS(int x, int y, int z) {
  queue<A> q;
  vsted[x][y][z] = 1;
  q.push({x, y, z}); // struct 이렇게 넣는구나.
  while(q.size()) {
    x = q.front().x; y = q.front().y; z = q.front().z; q.pop();
    if(vsted[0][0][0]) break;
    for(int i = 0; i < 6; i++) {
      int nx = max(0, x - b[i][0]);
      int ny = max(0, y - b[i][1]);
      int nz = max(0, z - b[i][2]);
      if(vsted[nx][ny][nz]) continue;
      vsted[nx][ny][nz] = vsted[x][y][z] + 1;
      q.push({nx, ny, nz});
    }
  }
  return vsted[0][0][0] - 1;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }

  cout << BFS(a[0], a[1], a[2]);
  return 0;
}