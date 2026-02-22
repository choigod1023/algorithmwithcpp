#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int start, end;
  cin >> n;
  vector<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    cin >> start >> end;
    pq.push_back({end, start});
  }
  stable_sort(pq.begin(), pq.end());
  int cnt = 0; // 정렬 후 첫째 항은 항상 사용하므로 1부터 시작
  int t = 0;   // 끝나는 시간을 체크하는 변수
  for (int i = 0; i < n; i++) {
    if (pq[i].second >= t) { // 끝나는 시간보다 시작하는 시간이 항상 크거다 같을
                             // 때, 끝나는 시간을 체크해서 변수에 넣어두기.
      cnt++;
      t = pq[i].first;
    }
  }
  cout << cnt << '\n';
}