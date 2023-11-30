#include <bits/stdc++.h>
using namespace std;

int t, k, n, d, ret, temp;
int a[1004][8], vsted[1004]; // 아
string s;

void print() {
    for(int i = 0; i < t; i++) {
        for(int j = 0; j < 8; j++) {
            cout << a[i][j];
        } 
        cout << '\n';
    }
    cout << '\n';
}

// n번 톱니바퀴를 d방향으로 돌린다.
void go(int n, int d) {
    vsted[n] = 1;
    // 왼쪽 톱니바퀴의 극이 다르면 반대방향으로 돌린다.
    if(n - 1 >= 0 && !vsted[n - 1] && a[n][6] != a[n - 1][2]) { // 아
        go(n - 1, -d);
    }
    // 오른쪽 톱니바퀴의 극이 다르면 반대방향으로 돌린다.
    if(n + 1 < t && !vsted[n + 1] && a[n][2] != a[n + 1][6]) {
        go(n + 1, -d);
    }
    
    if(d == 1) { // 시계 방향
        temp = a[n][7];
        for(int i = 7; i > 0; i--) {
            a[n][i] = a[n][i - 1];
        }
        a[n][0] = temp;
    }
    if(d == -1) { // 반시계 방향
        temp = a[n][0];
        for(int i = 0; i < 7; i++) {
            a[n][i] = a[n][i + 1];
        }
        a[n][7] = temp;
    }
}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> s;
        for(int j = 0; j < 8; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    cin >> k;
    // cout << '\n';
    while(k--) {
        cin >> n >> d; n--;
        memset(vsted, 0, sizeof(vsted));
        go(n, d);
        // print();
    }

    for(int i = 0; i < t; i++) {
        if(a[i][0] == 1) ret++; 
    }
    cout << ret << '\n';
    return 0;
}
