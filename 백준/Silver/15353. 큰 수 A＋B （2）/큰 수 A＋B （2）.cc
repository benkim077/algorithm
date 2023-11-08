#include <bits/stdc++.h>
using namespace std;

string A, B, ret;
int mx_size, carry;

int main() {
    cin >> A >> B;
    mx_size = max(A.size(), B.size());
    int size_gap = abs((int)A.size() - (int)B.size());
    if(A.size() > B.size()) {
        for(int i = 0; i < size_gap; i++) B = "0" + B;
    }
    else for(int i = 0; i < size_gap; i++) A = "0" + A;
    // cout << A << ' ' << B << '\n';
    reverse(A.begin(), A.end()); reverse(B.begin(), B.end());
    for(int i = 0; i < mx_size; i++) {
        
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        // cout << sum  << ' ';
        carry = 0;
        if(sum >= 10) {sum -= 10; carry++;};
        ret = to_string(sum) + ret;
    }
    if(carry) ret = to_string(carry) + ret;

    cout << ret << '\n';
    return 0;
}