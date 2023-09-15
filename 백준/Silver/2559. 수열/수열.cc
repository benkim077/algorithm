#include <bits/stdc++.h>
using namespace std;

int N, K, sum, mx, a;
vector<int> arr;

int main() {
  cin >> N;
  cin >> K;
  for(int i = 0; i < N; i++) {
    cin >> a;
    arr.push_back(a);
  }

  for(int i = 0; i < K; i++) { 
    sum += arr[i];
  }
  mx = sum;

  for(int i = 0; i < arr.size() - K; i++) {
    sum = sum - arr[i] + arr[i + K];
    if(sum > mx) mx = sum; 
  }
  cout << mx;
  return 0;
}

