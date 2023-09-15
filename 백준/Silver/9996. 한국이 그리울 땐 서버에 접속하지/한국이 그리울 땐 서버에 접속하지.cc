#include <bits/stdc++.h>
using namespace std;

string target, patt, prefix, suffix;
int idx, N;

bool solve(){
  if(prefix.size() + suffix.size() > target.size()) return false;
  if((target.substr(0, prefix.size()) == prefix)&&(target.substr(target.size()-suffix.size())) == suffix) return true;
  else return false;
}
int main(){
  cin >> N;
  cin >> patt;
  idx = patt.find('*');
  prefix = patt.substr(0, idx);
  suffix = patt.substr(idx + 1);

  for (int i = 0; i < N; i++){
    cin >> target;
    if (solve()) cout << "DA";
    else cout << "NE";
    cout << '\n';
  }
  return 0;
}