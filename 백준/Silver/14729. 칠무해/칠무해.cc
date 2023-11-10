#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<double> pq; // 가장 큰 값이 먼저 나온다.
vector<double> ret;

int main() {
    cin >> n;
    double score;
    for(int i = 0; i < n; i++) {
        cin >> score;
        if(pq.size() == 7) {
            pq.push(score);
            pq.pop();
        }
        else pq.push(score);
    }

    cout << fixed;
    cout.precision(3);
    while(pq.size()) {
        ret.push_back(pq.top());
        pq.pop();
    }
    reverse(ret.begin(), ret.end());
    for(double a : ret) cout << a << '\n';
    return 0;
}