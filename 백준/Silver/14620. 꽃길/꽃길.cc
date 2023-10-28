#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa

int N, y1, y2, y3, x1, x2, x3, mn = 200 * 5 * 3;
int a[14][14];
const int dy[] = {0, -1, 0, 1, 0}; // 자신, 상우하좌
const int dx[] = {0, 0, 1, 0, -1};

int _plus(int y, int x) {
  int _sum = 0;
  for(int i = 0; i < 5; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    _sum += a[ny][nx];
  }
  return _sum;
}

int get_price() {
  return _plus(y1, x1) + _plus(y2, x2) + _plus(y3, x3);
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < N*N; i++) {
    y1 = i / N;
    x1 = i % N;
    if(y1 < 1 || x1 < 1 || y1 >= N - 1 || x1 >= N - 1) continue;
    for(int j = i + 1; j < N*N; j++) {
      y2 = j / N;
      x2 = j % N;
      if(y2 < 1 || x2 < 1 || y2 >= N - 1 || x2 >= N - 1) continue;
      if(abs(y2 - y1) + abs(x2 - x1) < 3) continue;
      for(int k = j + 1; k < N*N; k++) {
        y3 = k / N;
        x3 = k % N;
        if(y3 < 1 || x3 < 1 || y3 >= N - 1 || x3 >= N - 1) continue;
        if(abs(y3 - y1) + abs(x3 - x1) < 3 || abs(y3 - y2) + abs(x3 - x2) < 3) continue;
        // cout << y1 << x1 << ' ' << y2 << x2 << ' ' << y3 << x3 << '\n';
        mn = min(mn, get_price());
      }
    }
  }
  cout << mn;
}