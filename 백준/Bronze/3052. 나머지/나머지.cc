#include <bits/stdc++.h>
using namespace std;

int a, cnt[46], ret;

int main() {
    for(int i = 0; i < 10; i++) {
        cin >> a; 
        cnt[a % 42]++;
    }
    for(int i = 0; i < 42; i++) {
        if(cnt[i] > 0) ret++;
    }
    cout << ret;
    return 0;
}