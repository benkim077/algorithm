#include <bits/stdc++.h>
using namespace std;

int a, b, lvl = 1;
bool done;
const int max_n = 500000;
int vsted[2][max_n + 4];

int main() {
  cin >> a >> b;
  if(a == b) {
    cout << 0;
    return 0;
  }
  queue<int> q;
  vsted[0][a] = 1;
  q.push(a);
  while(q.size()) {
    b += lvl;
    if(b > max_n) break;
    if(vsted[lvl % 2][b]) {
        done = true;
        break;
    }
    int q_size = q.size();
    for(int i = 0; i < q_size; i++) {
      int here = q.front(); q.pop();
      for(int there : {here + 1, here - 1, here * 2}) {
        if(there < 0 || there > max_n) continue;
        if(vsted[lvl % 2][there]) continue; // 홀/짝에 이미 도착했다면 더이상 할 필요 없음
        vsted[lvl % 2][there] = vsted[(lvl + 1) % 2][here] + 1;
        if(there == b) {
          done = true; break;
        }
        q.push(there);
      }
      if(done) break;
    }
    if(done) break;
    lvl++;
  }

  if(done) cout << lvl;
  else cout << -1;
  return 0;
}
