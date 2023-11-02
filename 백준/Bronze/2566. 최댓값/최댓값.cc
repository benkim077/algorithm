#include <bits/stdc++.h>
using namespace std;

int mx, y = 1, x = 1, elem;

int main() {
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            cin >> elem;
            if(elem > mx) {
                mx = elem;
                y = i; x = j;
            }
        }
    }
    cout << mx << '\n';
    cout << y << ' ' << x;
    return 0;
}