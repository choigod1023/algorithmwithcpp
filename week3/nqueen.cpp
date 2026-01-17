#include <iostream>
// #include <algorithm> // 불필요
// #include <stack>     // 불필요
// #include <string>    // 불필요
// #include <vector>    // 불필요
using namespace std;

int n;
int cnt = 0;

bool is_used_col[40];      // 열 ( | )
bool is_used_diag1[40];    // 우상향 대각선 ( / ) : 행 + 열
bool is_used_diag2[40];    // 좌상향 대각선 ( \ ) : 행 - 열 + n 

void back(int depth) // depth: 현재 보고 있는 '행(Row)'
{
    // [종료 조건]
    // 0 ~ n-1행까지 모두 배치를 마쳤으므로 n에 도달함
    if (depth == n) 
    {
        cnt++; 
        return;
    }

    // i: 현재 보고 있는 '열(Col)'
    for (int i = 0; i < n; i++) 
    {
        // [가지치기] 
        // 세로(col), 대각선1(/), 대각선2(\) 중 하나라도 공격받으면 패스
        // 코드에서는 (열 - 행 + n) 방식을 사용했으므로 주석도 맞춤
        if (is_used_col[i] || is_used_diag1[i + depth] || is_used_diag2[i - depth + n])
            continue;

        // [상태 저장] 방문 표시
        is_used_col[i] = true;
        is_used_diag1[i + depth] = true;
        is_used_diag2[i - depth + n] = true;

        // [재귀 호출] 다음 행(row)으로 이동
        back(depth + 1);

        // [상태 복구] 백트래킹 (나오면서 다시 원상복구)
        is_used_col[i] = false;
        is_used_diag1[i + depth] = false;
        is_used_diag2[i - depth + n] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    back(0);
    cout << cnt;
    
    return 0;
}