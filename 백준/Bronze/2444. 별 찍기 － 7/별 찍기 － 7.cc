#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    for(int i = 1; i < 2 * n - 1 + 1; i++) {
        for(int j = 0; j < abs(n - i); j++) {
            cout << ' ';
        }
        for(int j = 0; j < 2 * (n - abs(n - i)) - 1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}