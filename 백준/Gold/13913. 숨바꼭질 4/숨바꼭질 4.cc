#include <bits/stdc++.h>
using namespace std;

int N, K, visited[100004];
void BFS(int here) {
  queue<int> q;
  visited[here] = 1;
  q.push(here);
  while(q.size()) {
    here = q.front(); q.pop();
    for(int there : {here + 1, here - 1, here * 2}) {
      if(there < 0 || there > 100000) continue;
      if(visited[there] == 0) { // 방문한 적이 없음
        visited[there] = visited[here] + 1;
        q.push(there);
      }
    }
  }
}

int _vsted[100004];
vector<int> v;
void dfs_back(int here) {
  if(here == N) {
    reverse(v.begin(), v.end());
    return;
  }
  _vsted[here] = 1;
  for(int there : {here-1, here+1, here/2}) {
    if(there < 0 || there > 100000) continue;
    if(_vsted[there]) continue;
    if(visited[there] == visited[here] - 1) {
      _vsted[there] = 1;
      v.push_back(there);
      dfs_back(there);
      break;
    }
  }  
}


int main() {
  cin >> N >> K;

  BFS(N);
  v.push_back(K);
  dfs_back(K);
  cout << visited[K] - 1 << '\n';
  for(int a : v) {
    cout << a << ' ';
  } cout << '\n';
}
