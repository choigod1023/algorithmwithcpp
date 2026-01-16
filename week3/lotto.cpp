#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int k;
int arr[51];
int inp[15];
int is_check[51];

void back(int depth, int idx)
{
    // [Depth] 트리의 깊이가 6에 도달했나? (숫자 6개를 다 뽑았나?)
    if (depth == 6) 
    {
        for (int i = 0; i < 6; i++)
        {
            cout << arr[i] << ' '; 
        }
        cout << '\n';
        return; // 현재 깊이에서의 탐색 종료, 이전 깊이로 복귀(Backtracking)
    }

    // [Branch] 이번 깊이에서 선택할 수 있는 후보들을 탐색
    // idx부터 시작하는 이유: 조합(Combination)이므로 앞쪽 인덱스는 다시 보지 않음 (중복/순서 방지)
    for (int i = idx; i < k; i++) 
    {
        arr[depth] = inp[i]; // 현재 깊이(depth)의 상자에 i번째 숫자를 넣음
        
        // 다음 깊이(depth+1)로 내려가되, 
        // 다음 재귀에서는 현재 선택한 i의 다음(i+1)부터 탐색하도록 지시
        back(depth + 1, i + 1); 
    }
}int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
        {
            cin >> inp[i];
        }

        back(0, 0); //인자를 두개 받아서, 첫 번째 인자는 열탐색, 두 번째 인자는 행 탐색을 나타낸다. 
        cout<<'\n';
    }
    return 0;
}