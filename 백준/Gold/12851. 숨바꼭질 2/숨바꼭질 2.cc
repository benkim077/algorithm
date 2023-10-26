#include <bits/stdc++.h>
using namespace std;

int N, K, visited[100004], cnt[100004];

void BFS(int here) {
  queue<int> q;
  visited[here] = 1;
  cnt[here] = 1; // 이것도 마찬가지로 방문처리
  q.push(here);
  while(q.size()) {
    here = q.front(); q.pop();
    for(int there : {here + 1, here - 1, here * 2}) {
      if(there < 0 || there > 100000) continue;
      if(visited[there] == 0) { // 방문한 적이 없음
        visited[there] = visited[here] + 1;
        cnt[there] = cnt[here];
        q.push(there);
      } else if (visited[there] == visited[here] + 1) { // 방문한 적이 있으나, 거리가 같음
        cnt[there] += cnt[here];
      }
    }
  }
}


int main() {
  cin >> N >> K;

  BFS(N);

  cout << visited[K] - 1 << '\n' << cnt[K];
}
