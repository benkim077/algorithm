#include <bits/stdc++.h>
using namespace std;

int tri[3], a, b, c;

int main() {
    while(true) {
        cin >> tri[0] >> tri[1] >> tri[2];
        if(tri[0] == 0) break;
        sort(tri, tri + 3, greater<int>());
        a = tri[0]; b = tri[1]; c = tri[2];
        if(a >= b + c) cout << "Invalid";
        else if(a == b && b == c) cout << "Equilateral";
        else if((a == b && b != c) || (b == c && c != a) || (c == a && a != b)) cout << "Isosceles";
        else cout << "Scalene";
        cout << '\n';
    }
    return 0;
}