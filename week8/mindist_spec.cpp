#include <iostream>
#include <queue>
#include <vector>

#define INF 200000000 // 무한대 값 설정 (약 2억)

using namespace std;

// (비용, 노드번호) - C++ pair는 앞의 값을 기준으로 정렬함
vector<pair<int, int>> graph[20001];

vector<int> dijkstra(int start, int N) {
  vector<int> d(N + 1);
  for (int i = 1; i <= N; i++) {
    d[i] = INF; // 최단거리 배열을 INF로 초기화
  }
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
  return d;
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, E, K; // N는 정점의 개수, E는 간선의 개수. K는 시작 정점의 번호
  cin >> N >> E;
  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w; // u에서 v로 가는 가중치 w인 간선
    graph[u].push_back(
        {v,
         w}); // 그래프의 좌표를 u값으로, 그래프의 내부에는 첫값은 다음 목적지,
    // 두번째 값은 가중치
    graph[v].push_back({u, w}); // 양방향
  }
  int v1, v2;
  cin >> v1 >> v2; // v1과 v2 사이를 반드시 통과해야함.
  // 1 -> v1 -> v2 -> N
  // 1 -> v2 -> v1 -> N
  vector<int> d_from_1 = dijkstra(1, N);   // 1부터 N까지
  vector<int> d_from_v1 = dijkstra(v1, N); // v1에서 N까지
  vector<int> d_from_v2 = dijkstra(v2, N); // v2에서 N까지

  // 1 -> v1 -> v2 -> N
  long long path1 = (long long)d_from_1[v1] + d_from_v1[v2] + d_from_v2[N];
  // 1 -> v2 -> v1 -> N
  long long path2 = (long long)d_from_1[v2] + d_from_v2[v1] + d_from_v1[N];
  long long dmin = min(path1, path2); // 두 가지 경우의 수 중 가장 가중치가 낮은
  if (dmin >= INF)
    cout << -1;
  else
    cout << dmin;
  return 0;
}
