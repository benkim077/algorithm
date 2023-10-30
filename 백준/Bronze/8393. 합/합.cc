#include <bits/stdc++.h>
using namespace std;

int n, ret;

int main() {
    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        ret += i;
    }
    cout << ret;
}