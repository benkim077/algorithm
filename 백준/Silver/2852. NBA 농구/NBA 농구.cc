#include <bits/stdc++.h>
using namespace std;

int N, prevMM, prevSS, nowMM, nowSS, c1, c2, diff;
int scoreTeam; 
string scoreTime;
pair<int, int> t1, t2, temp;

pair<int, int> getTimeDiff(pair<int, int> now, pair<int, int> prev) {
  pair<int, int> ret = {0, 0};
  // SS
  if(now.second < prev.second) {
    now.first -= 1;
    now.second += 60;
  }
  ret.second = now.second - prev.second;
  // MM
  ret.first = now.first - prev.first;
  return ret;
}

void addTime() {
  temp = getTimeDiff({nowMM, nowSS}, {prevMM, prevSS});
  if(c1 > c2) {
    t1.first += temp.first;
    t1.second += temp.second;
  } else if (c1 < c2) {
    // cout << "hello?";
    t2.first += temp.first;
    t2.second += temp.second;
  }
}

int main() {
  cin >> N;
  for(int n = 0; n < N; n++) {
    // while(N--) { while 을 사용하면 N을 못쓴다..
    cin >> scoreTeam >> scoreTime;
    nowMM = atoi(scoreTime.substr(0, 2).c_str());
    nowSS = atoi(scoreTime.substr(3, 2).c_str());
    
    if(n != 0) addTime();
    
    if(scoreTeam == 1) c1++;
    else c2++;
    // cout << c1 << ' ' << c2 << '\n';

    prevMM = nowMM; prevSS = nowSS;
  }
  // 시합 종료까지 시간 계산
  nowMM = 48; nowSS = 0;
  addTime();

  // 60초 넘는 경우 처리
  if(t1.second >= 60) {
    t1.first += t1.second / 60;
    t1.second = t1.second % 60;
  }
  if(t2.second >= 60) {
    t2.first += t2.second / 60;
    t2.second = t2.second % 60;
  }
  
  // 출력
  cout.width(2); cout.fill('0');
  cout << t1.first << ':'; 
  cout.width(2); cout.fill('0');
  cout << t1.second << '\n';

  cout.width(2); cout.fill('0');
  cout << t2.first << ':'; 
  cout.width(2); cout.fill('0');
  cout << t2.second << '\n';

  return 0;
}