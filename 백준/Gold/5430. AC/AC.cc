#include <bits/stdc++.h>
using namespace std;

int t, n;
deque<int> q;
string p, input, ret;
bool is_error, is_reversed;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        q.clear();
        ret = "";
        is_error = false;
        is_reversed = false;
        
        cin >> p;
        cin >> n;
        cin >> input;
        int temp = 0;
        for(char c : input) {
            if(c == '[' || c == ']') continue;
            if(c >= '0' && c <= '9') {
                temp = temp * 10 + c - '0';
            } else {
                if(temp > 0) q.push_back(temp);
                temp = 0;
            }
        }
        if(temp > 0) q.push_back(temp);
        for(int i = 0; i < p.size(); i++) {
            if(p[i] == 'R') {
                is_reversed ? is_reversed = false : is_reversed = true;
            } else {
                if(q.size()) {
                    if(is_reversed) q.pop_back();
                    else q.pop_front();
                }
                else {
                    is_error = true;
                    break;
                }
            }
        }
        if(is_error) {
            cout << "error" << '\n';
            continue;
        }
        if(is_reversed) {
            reverse(q.begin(), q.end());
        }
        cout << '[';
        for(int i = 0; i < q.size(); i++) {
            cout << q[i];
            if(i == q.size() - 1) continue;
            cout << ',';
        }
        cout << ']';
        cout << '\n';
    }
    return 0;
}