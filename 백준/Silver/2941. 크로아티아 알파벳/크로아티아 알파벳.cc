#include <bits/stdc++.h>
using namespace std;

string croatian[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
string input;
int cnt;

int main() {
    cin >> input;
    for(string s : croatian) {
        while(input.find(s) != string::npos) {
            int idx = input.find(s);
            input.erase(idx, s.size());
            input.insert(idx, " ");
            cnt++;
        }
    }

    for(int i = 0; i < input.size(); i++) {
        if(input[i] != ' ') cnt++;
    }

    cout << cnt;
}