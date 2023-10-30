#include <bits/stdc++.h>
using namespace std;

int N, X;
int a[10004];

int main() {
    cin >> N >> X;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        if(a[i] < X) cout << a[i] << ' ';
    }
    return 0;
}