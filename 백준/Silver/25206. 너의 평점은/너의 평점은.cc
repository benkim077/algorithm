#include <bits/stdc++.h>
using namespace std;

string name, score;
double point;
double total, sum;

double change_number_point(string s) {
    if(s == "A+") return 4.5;
    if(s == "A0") return 4.0;
    if(s == "B+") return 3.5;
    if(s == "B0") return 3.0;
    if(s == "C+") return 2.5;
    if(s == "C0") return 2.0;
    if(s == "D+") return 1.5;
    if(s == "D0") return 1.0;
    if(s == "F") return 0.0;
    return 0.0;
}

int main() {
    for(int i = 0; i < 20; i++) {
        cin >> name >> point >> score;
        if(score == "P") continue;
        total += point;
        sum += point * change_number_point(score);
    }
    cout << sum / total;
}