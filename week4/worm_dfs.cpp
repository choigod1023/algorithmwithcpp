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
int cnt = 0;
void dfs(int v)
{
    visited_dfs[v] = true; //시작값(최상위,루트)에 대한 방문 처리.
    cnt++;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int next = graph[v][i]; //다음 간선에 대한 파악.
        if (!visited_dfs[next])
        {
            dfs(next); // 재귀를 통한 깊이 탐색
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
    dfs(v); // 시작값 v
    cout << cnt-1<<"\n";
}