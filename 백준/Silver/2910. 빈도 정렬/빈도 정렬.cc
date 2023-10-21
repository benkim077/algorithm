#include <bits/stdc++.h>
using namespace std;

int n, c, a;
struct st {
  int idx;
  int cnt;
};
map<int, st> mp;

bool cmp(pair<int, st> a, pair<int, st> b) {
  if(a.second.cnt == b.second.cnt) return a.second.idx < b.second.idx;
  return a.second.cnt > b.second.cnt;
}

int main() {
  cin >> n >> c;
  for(int i = 0; i < n; i++) {
    cin >> a;
    map<int, st>::iterator it = mp.find(a);
    if(it == mp.end()) {
      st s; s.idx = i; s.cnt = 1;
      mp.insert({a, s});
    }
    else (*it).second.cnt++;
  }

  // 정렬
  vector<pair<int, st>> v(mp.begin(), mp.end());
  sort(v.begin(), v.end(), cmp);
  for(auto a : v) {
    for(int i = 0; i < a.second.cnt; i++) {
      cout << a.first << ' ';
    }
  }
  return 0;
}