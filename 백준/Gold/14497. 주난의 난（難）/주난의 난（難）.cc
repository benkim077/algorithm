#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa

int N, M, a[304][304], cnt, vsted[304][304];
vector<pair<int, int>> v;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int y1, x1; // 시작
int y2, x2; // 도착
string input;
bool is_found;

void dfs(int y, int x) {
  vsted[y][x] = 1;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= N || nx >= M || vsted[ny][nx]) continue;
    // char로 입력받았음
    // #를 숫자로 치환했으면 좋았겠네
    // 오히려 더 귀찮아지는데?
    if(a[ny][nx] == '0') { 
      vsted[ny][nx] = 1;
      dfs(ny, nx);
    } else {
      vsted[ny][nx] = 1;
      v.push_back({ny, nx});
    }
  }
}

void go() {
  for(auto p : v) {
    // cout << p.first << p.second << "를 지움\n";
    a[p.first][p.second] = '0';
    if(p.first == y2 && p.second == x2) is_found = true;
  }
}

int main() {
  cin >> N >> M;
  cin >> y1 >> x1 >> y2 >> x2;
  y1--; x1--; y2--; x2--;
  for(int i = 0; i < N; i++) {
    cin >> input;
    for (int j = 0; j < M; j++) {
      a[i][j] = input[j];
      // cout << (char)a[i][j];
    }
    // cout << '\n';
  }

  while(!is_found) {
    // cout << "초기화\n"; 
    memset(vsted, 0, sizeof(vsted));
    v.clear();
    dfs(y1, x1);
    go();
    cnt++;
  }
  cout << cnt;
}
