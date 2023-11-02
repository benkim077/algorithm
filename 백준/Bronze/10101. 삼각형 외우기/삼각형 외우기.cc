#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;
    if(a + b + c != 180) cout << "Error";
    else if(a == b && b == c) cout << "Equilateral";
    else if((a == b && b != c) || (a != b && b == c) || (c == a && a != b)) cout << "Isosceles";
    else cout << "Scalene";
    return 0;
}