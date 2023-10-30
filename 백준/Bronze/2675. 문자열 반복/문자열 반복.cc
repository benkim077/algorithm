#include <bits/stdc++.h>
using namespace std;

int t, r;
string s;

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> r >> s;
        string ret = "";
        for(int j = 0; j < s.size(); j++) {
            for(int k = 0; k < r; k++) {
                ret += s[j];
            }
        }
        cout << ret << '\n';
    }
}