#include <bits/stdc++.h>
using namespace std;

int N, mx = INT_MIN;
bool check[14];
vector<int> a;
vector<char> b;
string s;

// void print() {
//   for(int i = 0; i < N / 2; i++) {
//     cout << check[i] << ' ';
//   }
//   cout << '\n';
// }

string make() {
  // 중첩된 괄호까지 한 번에 신경쓰려다 보니까, 로직이 매우 복잡해졌다!
  // 이렇게 하지 않으려면 어떻게 해야 하는가?
  // 로직을 구분해야 한다.
  // 예를 들어 A로직에 1, 2, 3 이라는 하위 로직이 있을 때,
  // "이 셋 중에 하나를 이전/이후에 처리할 수 있는가?"를 따져봐야 한다.
  for(int i = 1; i < N / 2; i++) {
    if(check[i] == check[i - 1] && check[i] == 1) return "";
  }

  string ret = "";
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
      ret += s[i];
    } else {
      // if(숫자일 때)
      // 숫자일 때로 생각하면 오히려 쉽다..
      // 로직이 어지럽다는 것은 상대적인 것이다. 
      // 내가 어지러우면 다른 방법을 생각해야 한다.
      // 연산자일 경우에 대해 주로 생각했었는데, 숫자로 생각하니까 훨씬 편해졌다.
      if((i + 1 < s.size()) && check[(i + 1) / 2] == true) ret += '(';
      ret += s[i];
      if((i - 1 >= 0) && check[(i - 1) / 2] == true) ret += ')';
    }
  }

  return ret;
}

void foo(string s) {
  // if(s.empty()) return;
  // for(int i = 0; i < s.size(); i++) {
  //   cout << s[i] << ' ';
  // }
  // cout << '\n';
  int i = 0;
  while(i < s.size()) {
    // cout << 'i' << i << '\n';
    if(s[i] == '(') {
      if(s[i + 2] == '+') {
        a.push_back(atoi(&s[i + 1]) + atoi(&s[i + 3]));
      } else if(s[i + 2] == '-') {
        a.push_back(atoi(&s[i + 1]) - atoi(&s[i + 3]));
      } else {
        a.push_back(atoi(&s[i + 1]) * atoi(&s[i + 3]));
      }
      i += 4;
    } else if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
      b.push_back(s[i]);
    } else {
      a.push_back(atoi(&s[i]));
    }
    i++;
  }
}

void go(int idx) {
  if(idx == N) {
    a.clear(); b.clear();
    foo(make());

    int ret = 0;
    if(a.empty()) return;
    for(int i = 0; i < a.size(); i++) {
      if(i == 0) {
        ret = a[i];
        continue;
      } 
      if(b[i - 1] == '+') {
        ret += a[i];
      } else if(b[i - 1] == '-') {
        ret -= a[i];
      } else {
        ret *= a[i];
      }
    }
    // cout << "ret" << ret << '\n';
    mx = max(mx, ret);
    return;
  }
  check[idx / 2] = 1;
  go(idx + 2);
  check[idx / 2] = 0;
  go(idx + 2);
}

int main() {
  cin >> N;
  cin >> s;

  go(1); 
  
  cout << mx;
  return 0;
}