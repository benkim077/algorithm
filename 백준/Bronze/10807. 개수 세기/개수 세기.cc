#include <bits/stdc++.h>
using namespace std;

int N, a[104], v, cnt;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> v;
    for(int i = 0; i < N; i++) {
        if(a[i] == v) cnt++;
    }
    cout << cnt;
    return 0;
}