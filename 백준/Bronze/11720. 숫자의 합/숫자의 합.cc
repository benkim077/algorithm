#include <bits/stdc++.h>
using namespace std;

string s;
int n, ret;

int main() {
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++) {
        ret += s[i] - '0';
    } 
    cout << ret;
    return 0;
}