#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
char sign_list[14];
int num_list[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
ll mx = 0, mn = 9876543210;
string mx_string, mn_string;

bool check(int a, int b, char c) {
  if(c == '<') return a < b;
  else return a > b;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> sign_list[i];
  }

  do {
    bool flag = true;
    string s = "";
    for(int i = 0; i < N; i++) {
      s += to_string(num_list[i]);
      if(!check(num_list[i], num_list[i + 1], sign_list[i])) {
        flag = false;
        break;
      }
    }
    s += to_string(num_list[N]);
    if(flag) {
      ll num = atoll(s.c_str());
      if(mx < num) {
        mx = num; mx_string = to_string(mx);
        if(s[0] == '0') {
          mx_string = '0' + mx_string;
        }
      }
      if(mn > num) {
        mn = num; mn_string = to_string(mn);
        if(s[0] == '0') {
          mn_string = '0' + mn_string;
        }
      }
    }
  } while (next_permutation(num_list, num_list + 10)); // sizeof(num_list) segfault

  cout << mx_string << '\n' << mn_string;
}