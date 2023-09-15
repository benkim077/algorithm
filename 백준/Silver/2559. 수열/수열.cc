#include <bits/stdc++.h>
using namespace std;

int N, K, temp, psum[100001], res = -10000004; 

int main() {
  cin >> N >> K;
  for (int i = 1; i < N + 1; i++) {
    cin >> temp;
    psum[i] = psum[i - 1] + temp;
  }
  for (int i = K; i <= N; i++) {
    res = max(res, psum[i] - psum[i - K]);
  }
  cout << res;
  return 0;
}