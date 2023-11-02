#include <bits/stdc++.h>
using namespace std;

int num_decimal, n;
string ret;

int main() {
    cin >> num_decimal >> n;

    int temp;
    while(num_decimal >= n) {
        temp = num_decimal % n;
        if(temp >= 10) ret += 'A' + temp - 10;
        else ret += num_decimal % n + '0';
        num_decimal /= n;
    }
    if(num_decimal >= 10) ret += 'A' + num_decimal - 10;
    else ret += num_decimal % n + '0';
    reverse(ret.begin(), ret.end());

    cout << ret;
    return 0;
}