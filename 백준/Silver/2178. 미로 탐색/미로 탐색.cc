#include <bits/stdc++.h>
using namespace std;

int N, M;
int mp[104][104];
int visited[104][104];
string temp;
queue<pair<int, int>> q;
pair<int, int> u;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void BFS(int y, int x) {  
  q.push({y, x});
  visited[y][x] = 1;
  while(q.size()) {
    u = q.front(); q.pop();
    for(int i = 0; i < 4; i++) {
      int ny = u.first + dy[i];
      int nx = u.second + dx[i];
      if(0 <= ny && ny < N && 0 <= nx && nx < M) {
        if(!visited[ny][nx]) {
          if(mp[ny][nx]) {
            q.push({ny, nx});
            visited[ny][nx] = visited[u.first][u.second] + 1;
          } 
        }
      }
    }
  }
  return;
} 

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> temp;
    for(int j = 0; j < M; j++) {
      mp[i][j] = temp[j] - '0'; 
    }
  }
  
  BFS(0, 0);

  cout << visited[N - 1][M - 1];
  return 0;
}