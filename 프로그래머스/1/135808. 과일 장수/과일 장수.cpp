#include <bits/stdc++.h>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int res = 0;
    sort(score.begin(), score.end(), greater<int>());
    
    vector<int> temp;
    for(int i = 0; i < score.size(); i++) {
        temp.push_back(score[i]);
        if(i % m == m - 1) {
            res += temp[(int)(min_element(temp.begin(), temp.end()) - temp.begin())] * m;
            temp.clear();
        } 
    }
    return res;
}