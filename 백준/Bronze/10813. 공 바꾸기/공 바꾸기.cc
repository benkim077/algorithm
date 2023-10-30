#include <bits/stdc++.h>
using namespace std;

int n, m, s, e;
int a[104];

int main() {
    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        a[i] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> s >> e;
        int temp = a[e];
        a[e] = a[s];
        a[s] = temp;
    }
    for(int i = 1; i < n + 1; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}