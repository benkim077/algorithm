#include <bits/stdc++.h>
using namespace std;

int a1, a0, c, n;
bool ok = 1;

int main() {
    cin >> a1 >> a0 >> c >> n;
    for(int i = n;;i++) {
        if(a1 * i + a0 <= c * i) {
            // 이 관계가 깨어지는 경우는? 왼쪽이 더 커지는 경우
            if(a1 > c) continue;
            else break;
        } else {
            ok = false;
            break;
        }
    }
    cout << ok;
    return 0;
}