#include <bits/stdc++.h>
using namespace std;

int N, i;
vector<int> v;

int main() {
  cin >> N;
  while(true) {
    i++;
    if(to_string(i).find("666") != string::npos) {
      v.push_back(i);
    }

    if(v.size() > 10000) break;
  }

  cout << v[N - 1];
  return 0;
}