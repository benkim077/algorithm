#include <bits/stdc++.h>
using namespace std;

int a[7], mx = 1, ret;

int main() {
    int num;
    for(int i = 0; i < 3; i++) {
        cin >> num;
        a[num]++;
    }

    for(int i = 1; i < 7; i++) {
        if(a[i] == 3) {
            ret = 10000 + i * 1000;
            break;
        } else if(a[i] == 2) {
            ret = 1000 + i * 100;
            break;
        } else if(a[i] == 1) {
            mx = max(mx, i);
            ret = mx * 100;
        } else ;
    }
    cout << ret;
}