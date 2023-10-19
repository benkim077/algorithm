#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s) {
  stack<char> stk;
  for(char c : s) {
    if(c == '[' || c == '(') stk.push(c);
    else {
      if(c == ']') {
        if(stk.size() && stk.top() == '[') stk.pop();
        else return false;
      }
      if(c == ')') {
        if(stk.size() && stk.top() == '(') stk.pop();
        else return false;
      }
    }
  }
  return stk.empty();
}

int main() {
  while(true) {
    // 한 줄을 입력받아야 한다
    // cin >> s;
    getline(cin, s);
    if(s == ".") break;

    if(check(s)) cout << "yes\n";
    else cout << "no\n";
  }
  return 0;
}