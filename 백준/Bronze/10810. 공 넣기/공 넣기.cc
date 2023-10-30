#include <bits/stdc++.h>
using namespace std;

int n, m;
int s, e, k;
int a[104];

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> k;
        for(int idx = s; idx < e + 1; idx++) {
            a[idx] = k;
        }
    }
    for(int i = 1; i < n + 1; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}