#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    while(cin >> a >> b) {
        if(a == b && a == 0) break;
        if(a % b == 0) cout << "multiple";
        else if(b % a == 0) cout << "factor";
        else cout << "neither"; 
        cout << '\n';
    }
    return 0;
}