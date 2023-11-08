#include <bits/stdc++.h>
using namespace std;

string input, temp;

int main() {
    cin >> input;
    temp = "";
    for(char c: input) {
        temp += c;
        if(temp.size() == 2 && (temp == "pi" || temp == "ka")) temp = "";
        if(temp.size() == 3 && temp == "chu") temp = "";
    }
    if(temp.empty()) cout << "YES";
    else cout << "NO";
    return 0;
}