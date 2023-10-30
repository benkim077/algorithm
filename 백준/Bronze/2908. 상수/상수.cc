#include <bits/stdc++.h>
using namespace std;

string a, b;

bool cmp(string x, string y) {
    return x < y;
}

int main() {
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(cmp(a, b)) cout << b;
    else cout << a;
    return 0;
}