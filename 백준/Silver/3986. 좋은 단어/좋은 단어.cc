#include <bits/stdc++.h>
using namespace std;

int N, res;
string str;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> str;
    stack<char> stk;
    if(str.size() & 1) continue;
    for(char c: str) {
      if(stk.size() != 0 && stk.top() == c) stk.pop();
      else stk.push(c);
    }
    if(stk.size() == 0) res++; 
  }
  cout << res << '\n';
  return 0;
}