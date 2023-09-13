#include <bits/stdc++.h>
using namespace std;

string s, alpha = "abcdefghijklmnopqrstuvwxyz";
map<char, int> mp;

int main() {
  for(char a : alpha) mp.insert({a, 0}); 
  
  cin >> s;
  for(char c : s) mp[c] += 1;
  
  for(auto kv: mp) cout << kv.second << ' ';
  return 0;
}