#include <bits/stdc++.h>
using namespace std;

int n, a, root, target;
vector<int> adj[54];

int dfs(int here) {
  // if(adj[here].empty()) return 1;
  int ret = 0;
  int child = 0;
  for(int there : adj[here]) {
    // 여기서 target을 제거(무시)하는데, 
    // 위에서 adj[here] empty를 하면 어떡하니
    if(there == target) continue; 
    ret += dfs(there);
    child++;
  }
  if(child == 0) return 1;
  return ret;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    if(a == -1) root = i;
    else adj[a].push_back(i);
  }
  
  cin >> target;
  if(target == root) cout << 0;
  else cout << dfs(root);
  return  0;
}
