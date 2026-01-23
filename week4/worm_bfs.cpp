//DFS 깊이 우선 탐색 : 트리로 생각했을 때 한 노드에 연결된 자손 노드까지 전부 파악한 후에 부모 노드로 올라옴.
//BFS 넓이 우선 탐색 : 한 노드에 인접한 노드들을 먼저 탐색한 후 자손 노드 탐색.
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[1001]; // 인접 리스트(Adjacency List): 각 정점에 연결된 이웃 정점들을 동적으로 저장.
bool visited_bfs[1001]={false,};//bfs에 대한 방문 배열. 이하동문.
int cnt =0;
void bfs(int v) // 넓이 우선 탐색
{
    queue<int> q;
    q.push(v); // 최초 시작값 큐에 넣기
    visited_bfs[v]= true; //시작값 방문 처리

    while(!q.empty()){ // 큐가 빌 때까지 반복 = 현재 시작점에서 도달 가능한 모든 정점을 방문했을 때 종료.
        int c = q.front(); // pop할 데이터값 확인
        q.pop();
        cnt++;
        for(int i=0;i<graph[c].size();i++){ 
            int next = graph[c][i]; // 한 노드에 여러 간선이 있으면 모두 큐에 들어가며, '먼저 들어간 순서대로' 다음 탐색의 기준(c)이 됨.
            if(!visited_bfs[next]){ //이미 방문했는지 확인
                q.push(next); // 다음 방문할 노드 push
                visited_bfs[next]=true; // 방문함 체크
            }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, v=1;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) // 간선 정보 입력 반복문
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(v);
    cout << cnt-1;

}