#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main() {
  cin >> T;
  while(T--) { // 초기화
    stack<char> stk;
    cin >> S;
    for(char c : S) {
      if(c == '(') stk.push(c);
      else {
        if(stk.size() && stk.top() == '(') stk.pop();
        else stk.push(c);
      }
    }

    if(stk.size()) cout << "NO" << '\n';
    else cout << "YES" << '\n';
  }  
  return 0;
}