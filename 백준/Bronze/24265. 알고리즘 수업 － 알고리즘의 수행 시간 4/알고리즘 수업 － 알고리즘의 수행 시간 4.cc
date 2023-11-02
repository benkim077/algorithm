#include <bits/stdc++.h>
using namespace std;

long long n, cnt;

int main() {
    cin >> n;
    for(int i = 1; i <= n - 1; i++) {
        for(int j = i + 1; j <= n; j++) {
            cnt++;
        }
    }
    cout << cnt << '\n' << 2;
    return 0;
}