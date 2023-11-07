#include <bits/stdc++.h>
using namespace std;

int n, m, S;
string oper;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> oper;
        if(oper == "add") {
            cin >> n;
            S |= (1 << n);
        } else if(oper == "remove") {
            cin >> n;
            S &= ~(1 << n);
        } else if(oper == "check") {
            cin >> n;
            if(S & (1 << n)) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if(oper == "toggle") {
            cin >> n;
            S ^= (1 << n);
        } else if(oper == "all") {
            S = (1 << 21) - 1;
        } else S = 0;
    }
    return 0;
}