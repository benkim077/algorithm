#include <bits/stdc++.h>
using namespace std;

int n, ret;
int a[104][104], y, x;

int main() {
    cin >> n;
    for(int k = 0; k < n; k++) {
        cin >> x >> y;
        for(int i = y; i < y + 10; i++) {
            for(int j = x; j < x + 10; j++) {
                a[i][j] = 1;
            }
        }
    }

    for(int i = 1; i < 101; i++) {
        for(int j = 1; j < 101; j++) {
            ret += a[i][j];
        }
    }
    cout << ret;
    return 0;
}