#include <bits/stdc++.h>
using namespace std;

string s;
int ret;

int alphabet_to_number(char c) {
    if(c == 'A' || c == 'B' || c == 'C') return 2;
    if(c == 'D' || c == 'E' || c == 'F') return 3;
    if(c == 'G' || c == 'H' || c == 'I') return 4;
    if(c == 'J' || c == 'K' || c == 'L') return 5;
    if(c == 'M' || c == 'N' || c == 'O') return 6;
    if(c == 'P' || c == 'Q' || c == 'R' || c == 'S') return 7;
    if(c == 'T' || c == 'U' || c == 'V') return 8;
    if(c == 'W' || c == 'X' || c == 'Y' || c == 'Z') return 9;
    return 0;
}

int main() {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        int num = alphabet_to_number(s[i]);
        ret += num + 1;
    }
    cout << ret;
    return 0;
}