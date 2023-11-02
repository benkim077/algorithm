#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;

int main() {
    cin >> n >> k;
    int i = 1;
    while(i <= n) {
        if(n % i == 0) {
            cnt++;
            if(cnt == k) break;
        }
        i++;
    }
    if(cnt < k) cout << 0;
    else cout << i;
    return 0;
}