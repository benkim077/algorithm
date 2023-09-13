#include <bits/stdc++.h>
using namespace std;

vector<int> v(9, 0);
int acc, n = 9, r = 7;

void print(vector<int> &v) {
  for(int i = 0; i < r; i++) {
    cout << v[i] << '\n';
  }
}

int main() {
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  do {
    acc = 0;
    for(int i = 0; i < r; i++) {
      acc += v[i];
    }
    if (acc == 100) {
      print(v);
      exit(0);
    }
  } while(next_permutation(v.begin(), v.end()));
}