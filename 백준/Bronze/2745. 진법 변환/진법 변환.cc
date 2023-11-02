#include <bits/stdc++.h>
using namespace std;

string num;
int n, ret;

int main() {
    cin >> num >> n;
    for(int i = 0; i < num.size(); i++) {
        int _num;
        if(num[i] < 65) _num = num[i] - '0';
        else _num = num[i] - 'A' + 10;
        ret += _num * (int)pow(n, num.size() - 1 - i);
    }
    cout << ret;
    return 0;
}