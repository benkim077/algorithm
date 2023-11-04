#include <bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv;
int mn = 500 * 15;
int table[19][5];// p, f, s, v, c
vector<pair<vector<int>, int>> ret;
// string 으로 변경하면 꼭 이런 문제가 발생한다. 주의해라.
// 10이상인 경우 string에서 숫자를 비교할 수 없다.
bool cmp(pair<vector<int>, int> a, pair<vector<int>, int> b) {
    if(a.second == b.second) {
        vector<int> v1 = a.first, v2 = b.first;
        int _mn_size = min(v1.size(), v2.size());
        // bool done = false;
        // 순회하면서 결론이 나면 break 결론이 나지 않으면 size가 더 긴 녀석이 더 크다.
        for(int i = 0; i < _mn_size; i++) {
            if(v1[i] == v2[i]) continue;
            return v1[i] < v2[i];
        } 
        return v1.size() < v2.size();
    }
    return a.second < b.second;
}

int main() {
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++) {
        cin >> table[i][0] >> table[i][1] >> table[i][2] >> table[i][3] >> table[i][4];
    }

    for(int i = 0; i < (1 << n); i++) {
        int psum = 0, fsum = 0, ssum = 0, vsum = 0, csum = 0; 
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                psum += table[j][0];
                fsum += table[j][1];
                ssum += table[j][2]; 
                vsum += table[j][3];
                csum += table[j][4];
            }
        }
        if(mp <= psum && mf <= fsum && ms <= ssum && mv <= vsum) {
            // 사전 순 정렬을 위해 넣을 때 부터 2진수로 변경
            // string temp = "";
            vector<int> temp = {};
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) temp.push_back(j + 1);
            }
            mn = min(mn, csum);
            ret.push_back({temp, csum});
        } 
    }
    
    if(ret.empty()) cout << -1;
    else {
        cout << mn << '\n';
        sort(ret.begin(), ret.end(), cmp);
        // for(int i = 0; i < ret.size(); i++) {
        //     for(int j = 0; j < ret[i].first.size(); j++) {
        //         cout << ret[i].first[j] << ' ';
        //     }
        //     cout << ret[i].second << '\n';
        // }
        for(int i = 0; i < ret[0].first.size(); i++) {
            cout << ret[0].first[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}