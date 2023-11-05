#include <bits/stdc++.h>
using namespace std;

const int mn_init = 987654321;
int n, mn = mn_init;
int a[14], vsted[14];
vector<int> adj[14];

void dfs(int S, int here, int approve_num) {
    if(approve_num == 1) vsted[here] = 1;
    else vsted[here] = 2;
    for(int there : adj[here]) {
        if(vsted[there]) continue;
        if(approve_num) {
            if((S & (1 << (there - 1))) == 0) continue;
        } else if(S & (1 << (there - 1))) continue;
        // if((S & (1 << (there - 1))) != approve_num) continue;
        if(approve_num == 1) vsted[there] = 1;
        else vsted[there] = 2;
        dfs(S, there, approve_num);
    }
    return;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i]; 
    // int no_connect = 0;
    // 결국 1이냐 0이냐가 발목을 잡는구만.. 어지럽다
    for(int i = 1; i < n + 1; i++) { 
        int _cnt;
        cin >> _cnt;
        // if(_cnt == 0) no_connect |= (1 << (i - 1)); // 반례 처리
        for(int j = 0; j < _cnt; j++) {
            int _adj;
            cin >> _adj;
            adj[i].push_back(_adj);
        }
    }
    // 반례
    // if(n == 2 && no_connect == (1 << n) - 1) {
    //     cout << -1;
    //     return 0;
    // }

    for(int i = 1; i < (1 << n) - 1; i++) { 
        // 숫자 i 하나로 그래프를 표현해야 함.
        memset(vsted, 0, sizeof(vsted));
        for(int j = 1; j < n + 1; j++) {
            if(vsted[j]) continue;
            if(i & (1 << (j - 1))) {
                dfs(i, j, 1);
                break;
            }
        }
        for(int j = 1; j < n + 1; j++) {
            if(vsted[j]) continue;
            if((i & (1 << (j - 1))) == 0) {
                dfs(i, j, 0);
                break;
            }
        }

        // cout << i << " : ";
        // for(int j = 1; j < n + 1; j++) cout << vsted[j] << ' ';
        // cout << '\n';
        bool all_vsted = true;
        for(int j = 1; j < n + 1; j++) {
            if(vsted[j] == 0) all_vsted = false;
        }
        if(all_vsted) {
            int asum = 0, bsum = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) asum += a[j];
                else bsum += a[j];
            }
            mn = min(mn, abs(asum - bsum));
        }
    }
    if(mn == mn_init) cout << -1;
    else cout << mn;
    return 0;
}