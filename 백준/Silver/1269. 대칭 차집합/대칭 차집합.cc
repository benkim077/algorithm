#include <bits/stdc++.h>
using namespace std;

int a, b, temp, ret;
set<int> a_set, b_set;

int main() {
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> a >> b;
    for(int i = 0; i < a; i++) {
        cin >> temp;
        a_set.insert(temp);
    }
    for(int i = 0; i < b; i++) {
        cin >> temp;
        b_set.insert(temp);
    }

    vector<int> v(a_set.size());
    auto it = set_difference(a_set.begin(), a_set.end(), b_set.begin(), b_set.end(), v.begin());
    v.erase(it, v.end());
    ret += v.size();

    v.clear(); v.resize(b_set.size());
    it = set_difference(b_set.begin(), b_set.end(), a_set.begin(), a_set.end(), v.begin());
    v.erase(it, v.end());
    ret += v.size();

    cout << ret;
    return 0;
}