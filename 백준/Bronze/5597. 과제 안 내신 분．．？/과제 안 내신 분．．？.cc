#include <bits/stdc++.h>
using namespace std;

int a[34];

int main() {
    for(int i = 0; i < 28; i++) {
        int b;
        cin >> b;
        a[b] = 1; 
    }
    for(int i = 1; i < 30 + 1; i++) {
        if(a[i] == 0) cout << i << '\n'; 
    }
    return 0;
}