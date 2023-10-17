#include <bits/stdc++.h>
using namespace std;

int N;
int a[104][104];
int b[104][104];
int visited[104][104];
// int rain;
int cnt;
int mx;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void DFS(int y, int x) {
  if(visited[y][x]) return;
  visited[y][x] = 1;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
    if(!b[ny][nx]) continue;
    DFS(ny, nx);
  }
  return;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  for(int rain = 0; rain < 101; rain++) {
    // 초기화
    cnt = 0;
    // fill(&b[0][0], &b[103][104], 0);
    for(int i = 0; i < 104; i++) {
      for(int j = 0; j < 104; j++) {
        b[i][j] = a[i][j];
      }
    }
    fill(&visited[0][0], &visited[103][104], 0); // 104라고 적었었는데 이거 때문에 틀렸었네..
    
    // 잠긴 지역 0으로
    for(int i = 0; i < 104; i++) {
      for(int j = 0; j < 104; j++) {
        if(b[i][j] <= rain) b[i][j] = 0;
      }
    }
    
    // 커넥티드 컴포넌트 구하기
    for(int i = 0; i < 104; i++) {
      for(int j = 0; j < 104; j++) {
        if(b[i][j] && !visited[i][j]) {
          DFS(i, j); // i-y, j-x
          cnt++;
        }
      }
    }

    // 최대값 구하기
    mx = max(mx, cnt); // mx의 초기값이 0일 때는 왜 안되는거지?
  }

  cout << mx; 

  return 0;
}