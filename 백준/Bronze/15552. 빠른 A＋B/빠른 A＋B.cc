#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main() {
    cin.tie(NULL); 
    cin.sync_with_stdio(false);
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> a >> b;
        cout << a + b << '\n';
    }    
    return 0;
}