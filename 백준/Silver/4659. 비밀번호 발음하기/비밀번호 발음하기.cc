#include <bits/stdc++.h>
using namespace std;

string pw, ret, checker = "aeiou", temp;
// queue<char> q;
vector<char> latest; // push를 하면서 size를 이용하는 로직으로 구현하기 위해서 vector를 사용.
bool flag1, flag2, flag3;

int main() {
  while(true) {
    latest.clear();
    cin >> pw;
    if(pw == "end") break;

    flag1 = false; flag2 = true; flag3 = true;
    for(char c : pw) {
      // flag1
      if(checker.find(c) != string::npos) flag1 = true; // string::npos

      // queue는 랜덤 엑세스가 불가능하므로, 좋지 않다. 배열을 사용하자
      // if(q.size() < 3) {
      //   q.push(c);
      // } else {
      //   q.pop();
      //   q.push(c);
      // }
      latest.push_back(c);
      // flag2
      temp = "";
      if(latest.size() >= 3) {
        for(int i = 1; i < 4; i++) {
          if(checker.find(latest[latest.size() - i]) != string::npos) {
            temp += 'a';
          } else {
            temp += 'b';
          }
        }
        // cout << latest.size() << ' ' << temp << '\n';
        if(temp == "aaa" || temp == "bbb") flag2 = false;        
      }

      // flag3
      if(latest.size() >= 2) {
        if(latest[latest.size() - 1] == latest[latest.size() - 2]) {
          if(latest[latest.size() - 1] == 'e' || latest[latest.size() - 1] == 'o') ;
          else {
            flag3 = false;
          }
        }
      }
    }

    // cout << flag1 << flag2 << flag3 << '\n';
    if(flag1 && flag2 && flag3) {
      ret = "<" + pw + "> is acceptable.";
    } else {
      ret = ret = "<" + pw + "> is not acceptable.";
    }
    cout << ret << '\n';
  }

  
  return 0;
}