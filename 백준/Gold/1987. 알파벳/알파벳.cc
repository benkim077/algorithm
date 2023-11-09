#include <bits/stdc++.h>
using namespace std;

int R, C, ret;
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1};
char a[24][24];


void go(int y, int x, int mask, int leng) {
    ret = max(ret, leng);
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        int _next = (1 << (a[ny][nx] - 'A'));
        if((mask & _next) == 0) {
            go(ny, nx, mask | _next, leng + 1);
        }
    }
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> a[i][j]; 
        }
    }

    go(0, 0, 1 << (a[0][0] - 'A'), 1);
    cout << ret << '\n';    
    return 0;
}