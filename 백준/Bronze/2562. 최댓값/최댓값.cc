#include <bits/stdc++.h>
using namespace std;

int mx = 0, th, a;

int main() {
    for(int i = 0; i < 9; i++) {
        cin >> a;
        if(mx < a) {
            mx = a;
            th = i + 1;
        }
    }
    cout << mx << '\n' << th;
    return 0;
}