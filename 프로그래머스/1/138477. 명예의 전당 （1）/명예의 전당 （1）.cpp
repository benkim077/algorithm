#include <bits/stdc++.h>
using namespace std;



vector<int> solution(int k, vector<int> score) {
    vector<int> res;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < score.size(); i++) {
        pq.push(score[i]);
        if(pq.size() > k) pq.pop();
        res.push_back(pq.top());
    }
    return res;
}