#include <bits/stdc++.h>
using namespace std;

int a[3];

int main() {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3, greater<int>());
    if(a[0] >= a[1] + a[2]) a[0] -= abs(a[0] - (a[1] + a[2])) + 1;
    cout << accumulate(a, a + 3, 0);
    return 0;
}