#include <bits/stdc++.h>
using namespace std;

string a, b, ret;
stack<char> stk;

int main() {
    cin >> a >> b;
    for(char c : a) {
        stk.push(c);
        if(stk.size() >= b.size()) {
            for(int i = b.size() - 1; i >= 0; i--) {
                if(stk.top() == b[i]) stk.pop();
                else {
                    string temp = b.substr(i + 1, b.size() - (i + 1));
                    for(char c : temp) stk.push(c);
                    break;
                }
            }
        }
    }
    while(stk.size()) {ret += stk.top(); stk.pop();}
    reverse(ret.begin(), ret.end());
    if(ret.empty()) cout << "FRULA" << '\n';
    else cout << ret << '\n';
    return 0;
}
