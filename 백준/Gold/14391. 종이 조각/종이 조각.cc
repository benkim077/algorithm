#include <bits/stdc++.h>
using namespace std;

int n, m, mx;
int a[4][4], b[4][4], vsted_a[4][4], vsted_b[4][4];
string input;

int solve(int c[4][4], int vsted[4][4], int n_size, int m_size) { // 2차원 배열의 길이를 얻는 방법?
    int _sum = 0;
    for(int i = 0; i < n_size; i++) {
        int temp = 0;
        for(int j = 0; j < m_size; j++) { 
            if(vsted[i][j]) temp = 10 * temp + c[i][j];
            else {
                _sum += temp;
                temp = 0;
            }
        }
        _sum += temp;
    }
    return _sum;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++) {
            a[i][j] = input[j] - '0';
            b[j][i] = a[i][j];
        }
    }

    for(int S = 0; S < (1 << n * m); S++) {
        // 비트마스킹으로 배열 만들기. 대칭된 배열도 함께 만든다.
        memset(vsted_a, 0, sizeof(vsted_a));
        memset(vsted_b, 0, sizeof(vsted_b));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int k = i * m + j;
                if(S & (1 << k)) vsted_a[i][j] = 1;
                else vsted_b[j][i] = 1;
            }
        }
        // for(int i = 0; i < n * m; i++) {
        //     if(S & (1 << i)) {
        //         vsted_a[n - (i / m) - 1][m - (i % m) - 1] = 1;
        //     } else {
        //         vsted_b[m - (i % m) - 1][n - (i / m) - 1] = 1;
        //     }
        // }
        // 만들어진 배열을 탐색
        mx = max(mx, solve(a, vsted_a, n, m) + solve(b, vsted_b, m, n));
    }   
    cout << mx << '\n';
    return 0;
}