#include <bits/stdc++.h>
using namespace std;

int ret;
string a, b;

int main() {
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < b.size(); i++) {
        int _sum = 0;
        for(int j = 0; j < a.size(); j++) {
            _sum += (a[j] - '0') * (b[i] - '0') * (int)pow(10, i + j);
        }
        ret += _sum;
        string s = to_string(_sum);
        cout << s.substr(0, s.size() - i) << '\n';
    }
    cout << ret;
}