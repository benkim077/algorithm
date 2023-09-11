#include <bits/stdc++.h>
using namespace std;

vector<int> keys, res;
int a, n = 9, r = 7;
void combi(int s, vector<int> v) {
  if (v.size() == r){
    int acc = 0;
    for (int a: v) {
      acc += keys[a];
    }
        
    if(acc == 100){
      for(int a : v){
        res.push_back(keys[a]);
      }
      sort(res.begin(), res.end());
      for(int a: res){
        cout << a << '\n';
      }
      exit(0);
    }
    return;
  }

  for(int i = s + 1; i < n; i++){
    v.push_back(i);
    combi(i, v);
    v.pop_back();
  }
  return;
}

int main(){
  for(int i = 0; i < n; i++){
    cin >> a;
    keys.push_back(a);
  }

  vector<int> v;
  combi(-1, v);
  return 0;
}