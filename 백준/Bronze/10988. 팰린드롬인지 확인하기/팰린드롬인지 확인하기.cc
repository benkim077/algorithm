#include <bits/stdc++.h>
using namespace std;

string str, reversedStr;
int main() {
  cin >> str;
  reversedStr = str;
  reverse(reversedStr.begin(), reversedStr.end());
  if(str == reversedStr) cout << 1;
  else cout << 0;
  return 0;
}