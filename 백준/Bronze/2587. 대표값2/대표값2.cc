#include <bits/stdc++.h>
using namespace std;

const int n = 5;
int a[n];

int main() {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << accumulate(a, a + n, 0) / n << '\n';
    cout << a[n / 2] << '\n';
    return 0;
}
