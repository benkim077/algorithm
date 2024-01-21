#include <bits/stdc++.h>
using namespace std;

int T, N, M, temp;
vector<int> v;

int check(int num) {
    int l = 0, r = v.size() - 1, mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if(num == v[mid]) return 1;
        else if(num < v[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        v.clear();
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        cin >> M;
        for(int i = 0; i < M; i++) {
            cin >> temp;
            cout << check(temp) << '\n';
        }
    }
    return 0;
}
