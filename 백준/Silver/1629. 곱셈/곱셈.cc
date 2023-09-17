#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c;

ll solve(ll b) {
  if (b == 1) return a % c;

  ll res = solve(b / 2);
  res = (res * res) % c;
  if (b & 1) res = (res * a) % c;
  return res;
}

int main() {
  cin >> a >> b >> c;
  cout << solve(b);
  return 0;
}