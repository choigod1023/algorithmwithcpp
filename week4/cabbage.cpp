#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 최대 크기 1000에 맞춰 배열 선언 (전역 변수는 0으로 자동 초기화)
int map[1001][1001];
bool visited_bfs[1001][1001];

// 상하좌우 탐색을 위한 방향 벡터 (y, x 순서)
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int cnt = 0;
queue<pair<int, int>> q;

void bfs(int i, int j, int n, int m)
{
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        int cy = cur.first;  // 현재 세로 좌표 (y)
        int cx = cur.second; // 현재 가로 좌표 (x)
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            // 1. 인덱스 범위 체크 (Index Out of Bounds 방지)
            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if (map[ny][nx] == 1 && !visited_bfs[ny][nx])
                {
                    q.push({ny, nx});
                    visited_bfs[ny][nx] = true;
                }
            }
        }
    }
}

int main()
{
    // 입출력 속도 향상 (백준 필수 테크닉)
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        int m, n, k;
        cin >> m >> n >> k; // M: 가로(열), N: 세로(행) 입력 순서 주의

        int dist_max = 0;

        for (int i = 0; i < n; i++)
            fill(map[i], map[i] + m, 0);
        for (int i = 0; i < n; i++)
            fill(visited_bfs[i], visited_bfs[i] + m, false);
        
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 1 && !visited_bfs[i][j])
                {
                    cnt++;
                    q.push({i, j});
                    visited_bfs[i][j]=true;
                    bfs(i, j, n, m);
                }
            }
        }

        // 결과 출력 (모든 토마토가 익는 데 걸리는 최소 일수)
        cout << cnt << '\n';
        cnt = 0;
    }

    return 0;
}