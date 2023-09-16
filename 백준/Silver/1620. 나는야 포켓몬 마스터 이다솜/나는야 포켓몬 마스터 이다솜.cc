#include <bits/stdc++.h>
using namespace std;

int N, M, t;
map<string, int> mp;
string arr[100004], temp;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N >> M;
  for (int i = 1; i < N + 1; i++) {
    cin >> temp;
    arr[i] = temp;
    mp.insert({temp, i});
  }

  for (int i = 0; i < M; i++) {
    cin >> temp;
    t = atoi(temp.c_str());
    if (t) {
      cout << arr[t];
    } else {
      cout << mp[temp];
    } 
    cout << '\n';
  }

  return 0;
}
