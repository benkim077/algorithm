#include <bits/stdc++.h>
using namespace std;

string s;
set<string> st_string;

int main() {
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> s;
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 0; j < s.size() - i + 1; j++) {
            st_string.insert(s.substr(j, i));
        }
    }
    cout << st_string.size();
    return 0;
}