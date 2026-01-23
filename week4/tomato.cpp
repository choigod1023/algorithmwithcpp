#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 최대 크기 1000에 맞춰 배열 선언 (전역 변수는 0으로 자동 초기화)
int map[1001][1001];
int dist[1001][1001];
bool visited_bfs[1001][1001];

// 상하좌우 탐색을 위한 방향 벡터 (y, x 순서)
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

void bfs(int n, int m) {
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int cy = cur.first;  // 현재 세로 좌표 (y)
        int cx = cur.second; // 현재 가로 좌표 (x)
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            // 1. 인덱스 범위 체크 (Index Out of Bounds 방지)
            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                // 2. 안 익은 토마토(0)이고 아직 방문하지 않은 곳인 경우만 탐색
                if (map[ny][nx] == 0 && !visited_bfs[ny][nx]) {
                    q.push({ny, nx});
                    visited_bfs[ny][nx] = true;
                    // [거리 업데이트] 이전 칸 소요 일수 + 1일 = 최단 일수 기록
                    dist[ny][nx] = dist[cy][cx] + 1;
                }
            }
        }
    }
}

int main() {
    // 입출력 속도 향상 (백준 필수 테크닉)
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n; 
    cin >> m >> n; // M: 가로(열), N: 세로(행) 입력 순서 주의

    // [초기화]: dist 배열을 -1로 채워 미방문 상태를 표시함
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            
            // [Multi-source BFS]: 익은 토마토(1)가 발견될 때마다 모두 큐에 삽입
            // 이렇게 하면 여러 지점에서 '동시다발적으로' 확산이 시작됨
            if (map[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0; // 시작점은 0일차
                visited_bfs[i][j] = true;
            }
        }
    }

    // BFS 탐색 시작 (물결이 퍼지듯 하루씩 전염됨)
    bfs(n, m);

    int dist_max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // [예외 처리]: 원래 토마토가 있던 자리(0)인데 거리가 -1이라면?
            // 사방이 벽에 막혀 영원히 익지 못한 토마토가 존재한다는 뜻
            if (map[i][j] == 0 && dist[i][j] == -1) {
                cout << -1 << "\n";
                return 0;
            }
            // 모든 칸을 확인하며 가장 늦게 익은 날짜(최댓값)를 업데이트
            dist_max = max(dist_max, dist[i][j]);
        }
    }

    // 결과 출력 (모든 토마토가 익는 데 걸리는 최소 일수)
    cout << dist_max << '\n';

    return 0;
}