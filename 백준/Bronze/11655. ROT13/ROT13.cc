#include <bits/stdc++.h>
using namespace std;

string str, res;
char a = 'a', z = 'z', A = 'A', Z = 'Z';

int main() {
  getline(cin, str);
  for(int i = 0; i < str.size(); i++){
    if (a <= str[i] && str[i] <= z) {
      if (str[i] + 13 > z) res += str[i] + 13 - 26;
      else res += str[i] + 13;
    } else if(A <= str[i] && str[i] <= Z) {
      if (str[i] + 13 > Z) res += str[i] + 13 - 26;
      else res += str[i] + 13;
    } else {
      res += str[i];
    }
  }

  cout << res;
  return 0;
}