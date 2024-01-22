#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int max_v = 1e9;
int N, M, temp, l, r, mid, ret = max_v;
vector<int> v;

bool check() {
    int num = 0;
    for(int i = 0; i < v.size(); i++) {
        num += v[i] / mid;
        if(v[i] % mid) num++;
    }
    return N >= num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    l = 1;
    for(int i = 0; i < M; i++) {
        cin >> temp;
        v.push_back(temp);
        r = max(r, temp);
    }

    while(l <= r) {
        mid = (l + r) / 2;
        if(check()) {
            ret = min(ret, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ret << '\n';
    return 0;
}
