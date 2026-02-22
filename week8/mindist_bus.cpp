#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9 // 무한대 값 설정 (약 10억)

using namespace std;

// (비용, 노드번호) - C++ pair는 앞의 값을 기준으로 정렬함
vector<pair<int, int>> graph[20001];
int d[20001]; // 최단 거리 테이블

void dijkstra(int start) {
  // 우선순위 큐 (최소 힙: 오름차순 정렬을 위해 greater 사용)
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  // 시작 노드 초기화
  pq.push({0, start});
  d[start] = 0;

  while (!pq.empty()) {
    // 가장 거리가 짧은 노드 꺼내기
    int dist = pq.top().first;
    int now = pq.top().second;
    pq.pop();

    // 현재 노드가 이미 처리된 적 있는 노드라면 무시
    if (d[now] < dist)
      continue;

    // 인접 노드 확인
    for (int i = 0; i < graph[now].size(); i++) {
      int cost = dist + graph[now][i].second;
      // 현재 노드를 거쳐서 가는 게 더 빠르다면 갱신
      if (cost < d[graph[now][i].first]) {
        d[graph[now][i].first] = cost;
        pq.push({cost, graph[now][i].first});
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M; // N개의 도시, M개의 버스
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w; // u에서 v로 가는 가중치 w인 간선
    graph[u].push_back(
        {v,
         w}); // 그래프의 좌표를 u값으로, 그래프의 내부에는 첫값은 다음 목적지,
    // 두번째 값은 가중치
  }
  int S, E; // S는 시작점, E는 도착점
  cin >> S >> E;
  for (int i = 1; i <= N; i++) {
    d[i] = INF; // 최단거리 배열을 INF로 초기화
  }
  dijkstra(S);
  cout << d[E] << '\n';

  return 0;
}
