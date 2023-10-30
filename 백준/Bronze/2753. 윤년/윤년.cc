#include <bits/stdc++.h>
using namespace std;

int a, ret;

int main() {
    cin >> a;
    if(a % 4 == 0) {
        if(a % 100 || a % 400 == 0) ret = 1;
        else ret = 0;
    }
    else ret = 0;
    cout << ret;
}