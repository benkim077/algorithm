#include <bits/stdc++.h>
using namespace std;

int K, N;
int tree[1028];
vector<int> ret[14];

// [start, end) 범위의 tree의 가운데 요소를 ret[lvl]에 담는 함수
void go(int start, int end, int lvl) {
  if(lvl == K) {
    return;
  }
  ret[lvl].push_back(tree[(start + end) / 2]);
  go(start, (start + end - 1) / 2, lvl + 1);
  go((start + end - 1) / 2 + 1, end, lvl + 1);
}

int main() {
  cin >> K;
  N = (int)pow(2, K) - 1;
  for(int i = 0; i < N; i++) {
    cin >> tree[i];
  }

  go(0, N, 0);
  for(int i = 0; i < K; i++) {
    for(int j = 0; j < ret[i].size(); j++) {
      cout << ret[i][j] << ' ';
    } cout << '\n';
  }
}