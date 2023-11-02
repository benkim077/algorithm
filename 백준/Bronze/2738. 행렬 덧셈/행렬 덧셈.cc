#include <bits/stdc++.h>
using namespace std;

int a[104][104], b[104][104];
int n, m;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }   
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> b[i][j];
        }   
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] + b[i][j] << ' ';
        }   
        cout << '\n';
    }
    return 0;
}