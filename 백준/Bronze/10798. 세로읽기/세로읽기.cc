#include <bits/stdc++.h>
using namespace std;

int a[20][20];
string input;

int main() {
    memset(a, -1, sizeof(a));
    int i = 0;
    while(getline(cin, input)) {
        for(int j = 0; j < input.size(); j++) {
            a[i][j] = input[j];
        }
        i++;
    }
    for(int j = 0; j < 15; j++) {
        for(int i = 0; i < 15; i++) {
            if(a[i][j] != -1) cout << (char)a[i][j];
        }
    }
    return 0;
}