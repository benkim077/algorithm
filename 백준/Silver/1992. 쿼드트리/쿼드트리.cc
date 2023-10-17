#include <bits/stdc++.h>
using namespace std;

int N;
string mp[68][68];
string temp, ret;

string recur(int y, int x, int l) {
  string acc = "";
  // 종료조건
  if(l == 1) {
    return mp[y - 1][x - 1];
  }

  // for(int i = y; i < y + l; i++) {
  //   for (int j = x; j < x + l; j++) {
  //     // 모든 정점을 확인할 필요가 있을까? -> 비효율
  //     // 그냥 호출해버리면 어떨까?
  //     // 그리고 마지막에 괄호 안에 있는 숫자가 0000 또는 1111이면 
  //     // 괄호와 함께 0 또는 1로 변환
  //     // acc += recur(i, j, l / 2);
  //   }
  // }
  acc += recur(y - l / 2 , x - l / 2, l / 2) + recur(y - l / 2, x, l / 2) + recur(y, x - l / 2, l / 2) + recur(y, x, l / 2);

  if(acc == "0000") return "0";
  else if(acc == "1111") return "1";
  else return "(" + acc + ")";
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> temp;
    for(int j = 0; j < N; j++) {
      mp[i][j] = temp[j];
    }
  }

  ret = recur(N, N, N); 

  // 스택에서 처리하려면 뒤에서 한 번에 하지 말고, 
  // 중간 중간 처리해야 함

  cout << ret;

  return 0;
}