#include <bits/stdc++.h>
using namespace std;

int TC;


int main() {
  cin >> TC;
  for(int i = 0; i < TC; i++) {
    int N, sum = 1;
    map<string, int> mp;
    string name, cate;

    cin >> N;
    for(int j = 0; j < N; j++) {
      cin >> name >> cate;
      mp[cate]++;
    }

    for(auto a: mp) sum = sum * (a.second + 1);
    sum = sum - 1;
    cout << sum << '\n';
  }
  return 0;
}