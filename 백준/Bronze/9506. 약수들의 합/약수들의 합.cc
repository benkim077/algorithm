#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main() {
    while(cin >> n) {
        string ret = "";
        v.clear();
        if(n == -1) break;
        for(int i = 1; i < n; i++) {
            if(n % i == 0) v.push_back(i);
        }
        if(accumulate(v.begin(), v.end(), 0) != n) ret = to_string(n) + " is NOT perfect.";
        else {
            ret += to_string(n) + " = ";
            for(int i = 0; i < v.size(); i++) {
                ret += to_string(v[i]);
                if(i == v.size() - 1) continue;
                ret += " + ";
            }
        }
        cout << ret << '\n';
    }
    return 0;
}