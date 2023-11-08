#include <bits/stdc++.h>
using namespace std;

int n, ret[200004], cnt, mx;
string s;
stack<int> stk;


int main() {
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') stk.push(i);
        else if(stk.size()) {
            ret[stk.top()] = 1;
            ret[i] = 1;
            stk.pop();
        }
    }

    for(int i = 0; i < n; i++) {
        if(ret[i]) {
            cnt++;
            mx = max(mx, cnt);
        } else {
            cnt = 0;
        }
    }
    cout << mx << '\n';
    return 0;
}