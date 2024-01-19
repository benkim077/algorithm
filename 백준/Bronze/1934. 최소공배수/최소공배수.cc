#include <bits/stdc++.h>
using namespace std;

int T, A, B, res;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> A >> B;
        cout << (A * B) / gcd(A, B) << '\n';
    }
}
