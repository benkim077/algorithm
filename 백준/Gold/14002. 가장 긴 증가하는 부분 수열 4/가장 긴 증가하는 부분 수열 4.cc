#include <bits/stdc++.h>
using namespace std;

int N, ret, idx;
int a[1004], dp[1004], prev_list[1004];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(prev_list, prev_list + 1004, -1);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if (dp[i] < dp[j] + 1) {
                    prev_list[i] = j;
                    dp[i] = dp[j] + 1;
                }
                // dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    idx = max_element(dp, dp + N) - dp;
    ret = dp[idx];

    cout << ret << '\n';
    while (true) {
        v.push_back(a[idx]);
        if (prev_list[idx] == -1) {
            break;
        }
        idx = prev_list[idx];
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
