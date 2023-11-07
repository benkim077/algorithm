#include <bits/stdc++.h>
using namespace std;

int n, m, mx;
int a[4][4], b[4][4], vsted_a[4][4], vsted_b[4][4];
string input;

int solve(int c[4][4], int vsted[4][4], int n_size, int m_size) {
    int _sum = 0;
    for(int i = 0; i < n_size; i++) {
        string temp;
        for(int j = 0; j < m_size; j++) {
            if(vsted[i][j]) temp += c[i][j];
            else if(temp.size()) {
                _sum += atoi(temp.c_str());
                temp = "";
            }
        }
        // cout << atoi(temp.c_str()) << '\n';
        _sum += atoi(temp.c_str());
        temp = "";
    }
    // cout << _sum << ' ';
    return _sum;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++) {
            a[i][j] = input[j];
            b[j][i] = a[i][j];
        }
    }

    for(int S = 0; S < (1 << n * m); S++) {
        // 비트마스킹으로 배열 만들기
        memset(vsted_a, 0, sizeof(vsted_a));
        memset(vsted_b, 0, sizeof(vsted_b));
        for(int i = 0; i < n * m; i++) {
            if(S & (1 << i)) {
                vsted_a[n - (i / m) - 1][m - (i % m) - 1] = 1;
            } else {
                vsted_b[m - (i % m) - 1][n - (i / m) - 1] = 1;
            }
        }
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << vsted_a[i][j];
        //     } cout << '\n';
        // }   cout << '\n';
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << vsted_b[i][j];
        //     } cout << '\n';
        // }   cout << '\n';
        mx = max(mx, solve(a, vsted_a, n, m) + solve(b, vsted_b, m, n));
        // cout << '\n';
    }   
    cout << mx << '\n';
    return 0;
}