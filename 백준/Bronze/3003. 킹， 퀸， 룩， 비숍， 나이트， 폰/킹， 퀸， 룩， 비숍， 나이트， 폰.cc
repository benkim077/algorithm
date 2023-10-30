#include <bits/stdc++.h>
using namespace std;

int a[6] = {1, 1, 2, 2, 2, 8};
int b;

int main() {
    for(int i = 0; i < 6; i++) {
        cin >> b;
        a[i] -= b;
        cout << a[i] << ' ';
    }
    return 0;
}