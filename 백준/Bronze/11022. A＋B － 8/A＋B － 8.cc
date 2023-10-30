#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main() {
    cin.tie(NULL); 
    cin.sync_with_stdio(false);
    cin >> T;
    for(int i = 1; i < T + 1; i++) {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a << " + " << b << " = " << a+b << "\n";
    }    
    return 0;
}