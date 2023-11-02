#include <bits/stdc++.h>
using namespace std;

int y, x, a, b;
map<int, int> mp_x, mp_y;

int main() {
    for(int i = 0; i < 3; i++) {
        cin >> a >> b;
        mp_x[a]++;
        mp_y[b]++;
    }
    for(auto p : mp_x) {
        if(p.second == 1) cout << p.first;
    }
    cout << ' ';
    for(auto p : mp_y) {
        if(p.second == 1) cout << p.first;
    }
    return 0;
}