#include <bits/stdc++.h>
using namespace std;

int N, ret;
int a[1004], cnt[1004];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        int mx = 0;
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) mx = max(mx, cnt[j]);
        }
        cnt[i] = mx + 1;
        ret = max(cnt[i], ret);
    }
    cout << ret << '\n';
    return 0;
}
