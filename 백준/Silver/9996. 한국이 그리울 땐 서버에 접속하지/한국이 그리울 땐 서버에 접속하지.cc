#include <bits/stdc++.h>
using namespace std;

int N, pos;
string target, patt , s, e;

bool solve(){
  for(int i = 0; i < s.size(); i++){
    if (target[i] != s[i]) return false;
  }
  for(int i = 0; i < e.size(); i++){
    if(target[target.size() - e.size() + i] != e[i]) return false;
  }
  return true;
}

int main(){
  cin >> N;
  cin >> patt;
  pos = patt.find('*');
  for(int i = 0; i < patt.size(); i++) {
    if (i < pos) s += patt[i];
    else if (i > pos) e += patt[i];
    else ;
  }
  for (int i = 0; i < N; i++){
    cin >> target;
    if (patt.size() - 1 > target.size()) cout << "NE";
    else {
      if (solve()) cout << "DA";
      else cout << "NE";
    }
    cout << '\n';
  }
  return 0;
}