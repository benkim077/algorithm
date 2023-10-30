#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        string ret = "";
        for(int j = 0; j < n - i; j++) {
            ret += " ";
        }
        for(int j = n - i; j < n; j++) {
            ret += "*";
        }
        cout << ret << '\n';
    }
    return 0;
}