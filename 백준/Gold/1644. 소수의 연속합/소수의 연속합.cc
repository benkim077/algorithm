#include <bits/stdc++.h>
using namespace std;

int n, s, e, sum, ret;
vector<int> p_num;

vector<int> eratos(int n) {
    vector<int> ret;
    if(n <= 1) return ret;

    bool a[n + 1];
    for(int i = 2; i < n + 1; i++) a[i] = true;

    for(int i = 2; i * i <= n; i++) {
        if(a[i]) {
            for(int j = i * i; j <= n; j += i) a[j] = false;
        }
    }

    for(int i = 2; i < n + 1; i++) {
        if(a[i] == true) ret.push_back(i);
    }
    return ret;
}

int main() {
    cin >> n;
    p_num = eratos(n);
    if(n < 2) {cout << 0; return 0;}

    sum = p_num[s];
    while(s <= e && s < p_num.size() && e < p_num.size() && p_num[s] <= n && p_num[e] <= n) {
        if(sum == n) { 
            ret++;
            e++; 
            sum += p_num[e]; 
        }
        else if(sum > n) {
            sum -= p_num[s];
            s++;
        }
        else if(sum < n) {
            e++;
            sum += p_num[e];
        }
        // cout << s << ' ' << e << '\n';
    }

    cout << ret;
    return 0;
}