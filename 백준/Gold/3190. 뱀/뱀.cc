#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, k, l, row, col, _leng = 1, t, d = 1, ret;
vector<pair<int, char>> v;
int vy, vx, vidx;
char c;
int a[104][104], vsted[104][104];

void go(int y, int x, int prev_vsted, int _time) {
    // cout << _time << ' ' << y << ' ' << x << '\n';
    if(a[y][x] == 1) {
        _leng++;
        a[y][x] = 0; // 사과가 없어진다.
        // cout << "현재 길이는 " << _leng << '\n';
    }
    // 밖으로 나가는 것을 먼저 확인
    // cout << vsted[y][x] << ' ' << prev_vsted << '\n';
    if(y < 0 || x < 0 || y >= n || x >= n || (vsted[y][x] - prev_vsted <= _leng)) {
        ret = _time;
        return;
    }

    if(_time == t) {
        if(c == 'D') d = (d + 1) % 4;
        else d = (d - 1) % 4;
        if(d < 0) d += 4;
        if(vidx + 1 < l) tie(t, c) = v[++vidx];
    }
    int ny = y + dy[d], nx = x + dx[d];
    int temp = vsted[ny][nx];
    vsted[ny][nx] = vsted[y][x] + 1;
    go(ny, nx, temp, _time + 1); // 이거 제대로 전
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        // 사과 위치
        cin >> row >> col;
        a[row - 1][col - 1] = 1;
    }
    cin >> l;
    for(int i = 0; i < l; i++) {
        cin >> t >> c;
        v.push_back({t, c});
    }

    tie(t, c) = v[vidx];
    // memset(vsted, -1, sizeof(vsted));
    fill(&vsted[0][0], &vsted[0][0] + 24 * 24, -1);
    vsted[0][0] = 1;
    go(0, 0, -1, 0);
    cout << ret << '\n';
    return 0;
}
