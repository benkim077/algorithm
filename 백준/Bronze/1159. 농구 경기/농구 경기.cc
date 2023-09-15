#include <bits/stdc++.h>
using namespace std;

string str, res;
int cnt[30];
int N;
int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> str;
    cnt[str[0] - 'a']++;
  }

  for(int i = 0; i < 26; i++) {
    if(cnt[i] >= 5) res += (char)(i + 'a');
  }

  if (res.size()) cout << res;
  else cout << "PREDAJA";
  return 0;
}