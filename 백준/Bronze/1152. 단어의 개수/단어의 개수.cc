#include <bits/stdc++.h>
using namespace std;

int cnt;
string s;

int main() {
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') cnt++;
    }
    if(s[0] == ' ') cnt--;
    if(s[s.size() - 1] == ' ') cnt--;
    cout << cnt + 1;
    return 0;
}