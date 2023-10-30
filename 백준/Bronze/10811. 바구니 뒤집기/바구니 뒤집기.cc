#include <bits/stdc++.h>
using namespace std;

int a[104], n, m, s, e;

int main() {
    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        a[i] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> s >> e;
        reverse(a + s, a + e + 1); 
    }
    for(int i = 1; i < n + 1; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}