#include <bits/stdc++.h>
using namespace std;

int n, vsted[30], cnt;
string s;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        bool group = true;
        memset(vsted, 0, sizeof(vsted));
        for(int j = 0; j < s.size(); j++) {
            if(vsted[s[j] - 'a']) {
                if(s[j] == s[j - 1]) {
                    continue;
                } else {
                    group = false;
                    break;
                }
            } else {
                vsted[s[j] - 'a'] = 1;
            }
        } 
        if(group) cnt++;
    }
    cout << cnt;
    return 0;
}