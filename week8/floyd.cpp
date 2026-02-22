#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9 // 무한대 값 설정 (약 10억)

using namespace std;

int d[101][101];
int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n;
  cin >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = INF; // 최단거리 배열을 INF로 초기화
      if (i == j)
        d[i][j] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w; // u에서 v로 가는 가중치 w인 간선

    d[u][v] = min(d[u][v], w);
    // u에서 v로 가는 버스가 여러 개라면, 그 중에서 가장 저렴한 비용만 저장해야.
  }
  // 점화식에 따라 플로이드 워셜 알고리즘 수행
  for (int k = 1; k <= n; k++) {     // 거쳐가는 노드
    for (int i = 1; i <= n; i++) {   // 출발 노드
      for (int j = 1; j <= n; j++) { // 도착 노드
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[i][j] == INF) {
        cout << 0 << " ";
      } else
        cout << d[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
