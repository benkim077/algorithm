#include <bits/stdc++.h>
using namespace std;

int N, L, R, num, result;
int a[54][54], mp[54][54];
// vector<pair<int, int>> u[2504];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
bool updated;

void makeMap() {
  num = 0; memset(mp, 0, sizeof(mp)); 
  vector<pair<int, int>> u[2504];
  // for(auto v : u) v.clear(); // u를 초기화
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < N; x++) {
      for(int i = 1; i < 3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        // if(mp[ny][nx] == mp[y][x] && mp[y][x] != 0) continue;
        if(L > abs(a[ny][nx] - a[y][x]) || abs(a[ny][nx] - a[y][x]) > R) continue;
        if(mp[ny][nx] == 0 && mp[y][x] == 0) {
          num++;
          mp[ny][nx] = num; mp[y][x] = num;
          u[num].push_back({ny, nx}); u[num].push_back({y, x});
        } else if(mp[ny][nx] != 0 && mp[y][x] == 0) {
          mp[y][x] = mp[ny][nx];
          u[mp[ny][nx]].push_back({y, x});
        } else if(mp[ny][nx] == 0 && mp[y][x] != 0) {
          mp[ny][nx] = mp[y][x];
          u[mp[y][x]].push_back({ny, nx});
        } else if(mp[ny][nx] != 0 && mp[y][x] != 0 && mp[ny][nx] != mp[y][x]) { 
          // 다른 팀이어야 합치지
          // cout << y << x << ' ' << ny << nx << "합쳐져라" << '\n';
          for(auto p : u[mp[ny][nx]]) {
            mp[p.first][p.second] = mp[y][x];
            u[mp[y][x]].push_back({p.first, p.second});
          }
          // u[mp[ny][nx]].clear(); // 벡터가 클리어가 안됐네
          // u[mp[ny][nx]].clear();
        }
      }
    }
  }
}

void print() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << mp[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';cout << '\n';
}

void update() {
  for(int i = 1; i <= num; i++) {
    int sum = 0; int cnt = 0;
    for(int y = 0; y < N; y++) {
      for(int x = 0; x < N; x++) {
        if(mp[y][x] == i) {
          sum += a[y][x]; 
          cnt++;
        }
      }
    }
    // for(pair<int, int> p : u[i]) {
    //   sum += a[p.first][p.second];
    //   cnt++;
    // }
    if(cnt == 0) continue;
    int avg = sum / cnt;
    // cout << "avg is " << avg << '\n';
    for(int y = 0; y < N; y++) {
      for(int x = 0; x < N; x++) {
        if(mp[y][x] == i && a[y][x] != avg) { 
          // 두 번째 조건은 필요가 없을듯 
          a[y][x] = avg;
          updated = true;
        }
      }
    }
    // for(pair<int, int> p : u[i]) {
    //   if(a[p.first][p.second] != avg) {
    //     a[p.first][p.second] = avg;
    //     updated = true;
    //   }
    // }
  }
}

int main() {
  cin >> N >> L >> R;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  while(true) {
    makeMap();
    // print(); 
    // update 함수에서 한 번이라도 업데이트 된 이력이 있으면 update = true;
    updated = false;
    update();
    if(!updated) break;
    else result++;
  }
  
  cout << result;
}