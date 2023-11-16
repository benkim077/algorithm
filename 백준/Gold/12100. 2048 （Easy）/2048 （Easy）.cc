#include <bits/stdc++.h>
using namespace std;
int n, ret;
struct Board {
    int a[24][24];
    void _move() {
        int temp[24][24];
        for(int i = 0; i < n; i++){
            int c = -1, d = 0;
            for(int j = 0; j < n; j++){
                if(a[i][j] == 0) continue;
                if(d && a[i][j] == temp[i][c]) temp[i][c] *= 2, d = 0;
                else temp[i][++c] = a[i][j], d = 1;
            }
            for(c++; c < n; c++) temp[i][c] = 0;
        }
        memcpy(a, temp, sizeof(a));
    }
    void _rotate() {
        int temp[24][24];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[i][j] = a[n - j - 1][i];
            }
        }
        memcpy(a, temp, sizeof(a));
    }
    void _get_max() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ret = max(ret, a[i][j]);
            }
        }
    }
}; // struct 끝날 때 ;;;;;;;;

void go(Board c, int cnt) {
    if(cnt == 5) {
        c._get_max();
        return;
    }
    for(int i = 0; i < 4; i++) {
        Board d = c; // 얕은 복사
        d._move();
        go(d, cnt + 1);
        c._rotate();
    }
}

int main() {
    cin >> n;
    Board c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c.a[i][j];
        }
    }
    go(c, 0);
    cout << ret << '\n';
    return 0;
}