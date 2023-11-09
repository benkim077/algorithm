#include <bits/stdc++.h>
using namespace std;

int n, l;
int a[104][104], b[104][104];

int solve(int a[104][104]) {
    int _ret = 0;
    bool done;
    int _cnt;
    for(int i = 0; i < n; i++) {
        done = true;
        _cnt = 0;
        for(int j = 0; j < n; j++) { 
            _cnt++;
            if(j == n - 1) {
                if(_cnt < 0) done = false;
                continue;
            }
            if(a[i][j] + 1 == a[i][j + 1]) { // 오르막
                if(_cnt < l) {
                    done = false;
                    break;
                } else {
                    _cnt = 0;
                }
            } else if(a[i][j] - 1 == a[i][j + 1]) { // 내리막
                if(_cnt >= 0) _cnt = -l;
                else {
                    done = false;
                    break;
                }
            } else if(a[i][j] == a[i][j + 1]) { // 높이가 같음
                continue;
            } else { // 높이차가 1 초과인 경우
                done = false;
                break;
            }
        }
        if(done) {
            // cout << i << "번째 성공\n";
            _ret++;
        }
    }
    return _ret;
}

int main() {
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    cout << solve(a) + solve(b) << '\n';
    return 0;
}