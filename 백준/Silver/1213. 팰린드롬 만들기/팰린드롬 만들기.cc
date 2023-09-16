#include <bits/stdc++.h>
using namespace std;

string name, front, mid, back;
int flag, cnt[26];

int main() {
  cin >> name;
  for (int i = 0; i < name.size(); i++) {
    cnt[name[i] - 'A']++;
  }

  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2) {
      flag++;
      mid = (char)(i + 'A');
      cnt[i]--;
    }
    for (int j = 0; j < (int)(cnt[i] / 2); j++) {
      front = front + (char)(i + 'A');
      back = char(i + 'A') + back;
    }
  }

  if (flag > 1) cout << "I'm Sorry Hansoo";
  else cout << front << mid << back;
}