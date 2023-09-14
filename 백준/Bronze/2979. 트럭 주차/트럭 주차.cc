#include <bits/stdc++.h>
using namespace std;

int cnt[105];
int sum, A, B, C, s, e, pay;

int main() {
  cin >> A >> B >> C;
  for(int i = 0; i < 3; i++) {
    cin >> s >> e;
    for(int i = s; i < e; i++) {
      cnt[i]++;
    }
  }
  for(int i = 1; i < 101; i++) {
    if (cnt[i] == 1) sum += A;
    else if (cnt[i] == 2) sum += 2 * B;
    else if (cnt[i] == 3) sum += 3 * C;
  }
  cout << sum;
  return 0;
}