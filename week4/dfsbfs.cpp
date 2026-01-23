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
bool visited_dfs[1001]={false,}; //dfs에 대한 방문 배열. graph의 값이 인덱스로 들어가며, 값은 참(방문함)/거짓(방문하지 않음)으로 나뉨.

bool visited_bfs[1001]={false,};//bfs에 대한 방문 배열. 이하동문.
void dfs(int v)
{
    visited_dfs[v] = true; //시작값(최상위,루트)에 대한 방문 처리.
    cout << v << " "; // 시작값 출력
    for (int i = 0; i < graph[v].size(); i++)
    {
        int next = graph[v][i]; //다음 간선에 대한 파악.
        if (!visited_dfs[next])
        {
            dfs(next); // 재귀를 통한 깊이 탐색
        }
    }
}

void bfs(int v) // 넓이 우선 탐색
{
    queue<int> q;
    q.push(v); // 최초 시작값 큐에 넣기
    visited_bfs[v]= true; //시작값 방문 처리

    while(!q.empty()){ // 큐가 빌 때까지 반복 = 현재 시작점에서 도달 가능한 모든 정점을 방문했을 때 종료.
        int c = q.front(); // pop할 데이터값 확인
        q.pop();
        cout << c << " "; // pop한 데이터 출력
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
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 1; i <= m; i++) // 간선 정보 입력 반복문
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) // 문제조건 "단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,"에 대한 처리.
    {
        sort(graph[i].begin(), graph[i].end()); // 내부 간선 값에 대한 정렬
    }
    dfs(v); // 시작값 v
    cout << "\n";
    bfs(v);
}