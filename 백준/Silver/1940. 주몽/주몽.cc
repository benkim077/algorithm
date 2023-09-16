#include <bits/stdc++.h>
using namespace std;

int source[100001];
int N, M, temp, res;

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> temp;
    source[temp]++;
  }
  
  if (M > 200000) cout << 0;
  else {
    for (int i = 1; i < 50001; i++) {
      if (M - i > 0 && i != M - i) {
        while(source[i] > 0 && source[M - i] > 0) {
          res++;
          source[i]--; source[M - i]--;
        }
      }
    }

    cout << res << '\n';
  }
  return 0;
}