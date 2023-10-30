#include <bits/stdc++.h>
using namespace std;

int N;
string ret;

int main() {
    cin >> N;
    N = N / 4;
    for(int i = 0; i < N; i++) {
        ret += "long ";
    }
    ret += "int";
    cout << ret;
    return 0;
}