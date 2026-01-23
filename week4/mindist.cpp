// DFS 깊이 우선 탐색 : 트리로 생각했을 때 한 노드에 연결된 자손 노드까지 전부 파악한 후에 부모 노드로 올라옴.
// BFS 넓이 우선 탐색 : 한 노드에 인접한 노드들을 먼저 탐색한 후 자손 노드 탐색.
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
using namespace std;
string map[101];
int dist[101][101];

// 상, 하, 좌, 우 = dx[i]+dy[i]
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int n, int m) // 넓이 우선 탐색
{
    queue<pair<int, int>> q;
    q.push({0, 0}); // 최초 시작값 큐에 넣기
    dist[0][0] = 1;

    while (!q.empty())
    {
        pair<int, int> pa = q.front(); // pop할 데이터값 확인
        int cy = pa.first;
        int cx = pa.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if((ny<n && nx<m && ny>=0 && nx>=0)&&(map[ny][nx]=='1')&&(dist[ny][nx]<0))
                {
                    q.push({ny,nx});
                    dist[ny][nx]=dist[cy][cx]+1;
                }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> map[i];
    }
    for(int i = 0; i < n; i++) {
    fill(dist[i], dist[i] + m, -1);
}
    bfs(n,m);
    cout << dist[n-1][m-1];
}