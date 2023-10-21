#include <bits/stdc++.h>
using namespace std;

int n;
string s, temp;
bool isNum;
vector<string> ret;

string eraseFrontZero(string s) {
  while(s[0] == '0') {
    s.erase(0, 1);
  }
  if(s == "") return "0";
  return s;
}

bool cmp(string a, string b) {
  if(a.size() == b.size()) return a < b;
  return a.size() < b.size();
}
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s;
    temp = "";
    isNum = false;
    for(char c: s) {
      if(c < 65) {
        temp += c;
        isNum = true;
      }
      else {
        if(isNum) {
          ret.push_back(eraseFrontZero(temp));
          temp = "";
          isNum = false;
        }
        else continue;
      }
    }
    // cout << eraseFrontZero(temp);
    if(isNum) ret.push_back(eraseFrontZero(temp));
  }
  sort(ret.begin(), ret.end(), cmp);
  for(string a : ret) {
    cout << a << '\n';
  } 
  return 0;
}