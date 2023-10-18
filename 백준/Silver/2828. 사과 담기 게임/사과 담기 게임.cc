#include <bits/stdc++.h>
using namespace std;

int N, M, J, loc, s, e, cnt, ret;

int main() {
  cin >> N >> M;
  s = 0;
  e = s + M;
  
  cin >> J;
  while(J--) {
    cin >> loc;
    loc -= 1;
    if(loc < s) {
      cnt = (s - loc);
      s -= cnt; e -= cnt;
    } else if(e <= loc) {
      cnt = loc - e + 1;
      s += cnt; e += cnt; 
    } else {
      cnt = 0;
    }
    ret += cnt;
  }

  cout << ret;
  return 0;
}