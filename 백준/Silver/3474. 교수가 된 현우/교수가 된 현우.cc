#include <bits/stdc++.h>
using namespace std;

int tc, n, ret;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
  cin >> tc;
  for(int i = 0; i < tc; i++) {
    cin >> n;
    ret = 0;
    for(int j = 5; j <= n; j *= 5) {
      ret += n / j;
    }
    cout << ret << '\n';
  }
}