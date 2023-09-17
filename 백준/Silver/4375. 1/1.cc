#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;

int main() {
  while(cin >> N) {
    ll num = 1, res = 1;
    while(true) {
      if (num % N == 0) {
        cout << res << '\n'; 
        break;
      }
      num = (10 * num) + 1;
      num = num % N;
      res++;
    }
  }
  return 0;
}