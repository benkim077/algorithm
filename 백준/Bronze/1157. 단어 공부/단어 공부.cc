#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[30];
int mx = 0;
vector<char> ret;

int main() {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] < 97) {
            cnt[s[i] - 'A']++;
        } else {
            cnt[s[i] - 'a']++;
        }
    }

    for(int i = 0; i < 26; i++) {
        mx = max(mx, cnt[i]);
    }
    for(int i = 0; i < 26; i++) {
        if(cnt[i] == mx) ret.push_back(i + 'A');
    }
    if(ret.size() > 1) cout << '?';
    else cout << ret[0];
    return 0;
}