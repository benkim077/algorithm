#include <bits/stdc++.h>
using namespace std;

int x, y, ret;;

int main() {
    cin >> x >> y;
    if(x > 0) {
        if(y > 0) ret = 1;
        else ret = 4;
    } else {
        if(y > 0) ret = 2;
        else ret = 3;
    }
    cout << ret;
}