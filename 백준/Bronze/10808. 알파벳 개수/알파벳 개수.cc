#include <bits/stdc++.h>
using namespace std;

string s, alpha = "abcdefghijklmnopqrstuvwxyz";
map<char, int> mp;
int cnt;

int main() {
  cin >> s;
  sort(s.begin(), s.end());

  for(char a : alpha) {
    cnt = 0;
    cnt = upper_bound(s.begin(), s.end(), a) - lower_bound(s.begin(), s.end(), a);
    cout << cnt << ' '; 
  }
}