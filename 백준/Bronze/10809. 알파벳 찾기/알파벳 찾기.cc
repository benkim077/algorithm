#include <bits/stdc++.h>
using namespace std;

int a[30];
string s;

int main() {
    cin >> s;
    memset(a, -1, sizeof(a));
    for(int i = 0; i < s.size(); i++) {
        if(a[s[i] - 'a'] == -1) a[s[i] - 'a'] = i;
    }
    for(int i = 0; i < 26; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}