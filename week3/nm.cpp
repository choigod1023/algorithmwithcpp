#include <iostream>
#include <algorithm>
// #include <stack>  // 안 쓰임
// #include <string> // 안 쓰임
// #include <vector> // 안 쓰임
using namespace std;

int m, n;
int arr[10];      // 수열을 담을 배열 (0번째 칸, 1번째 칸...)
bool is_check[10]; // 특정 숫자가 이미 사용되었는지 체크 (중복 방지)

// k: 현재 채우고 있는 수열의 위치 (0번째 칸부터 시작)
void back(int k)
{
    // [종료 조건]
    // m개를 모두 선택했다면 (깊이의 끝에 도달)
    if (k == m) 
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' '; // 완성된 수열 출력
        }
        cout << '\n';
        return;
    }

    // [후보 탐색]
    // 1부터 n까지의 숫자(카드)를 하나씩 시도
    for (int i = 1; i <= n; i++) 
    {
        // [가지치기] 이미 사용한 숫자인가?
        // 예: 이미 1을 썼는데 또 1을 쓰려고 하면(1, 1) 패스!
        if (!is_check[i]) 
        {
            arr[k] = i;      // k번째 칸에 숫자 i를 넣음
            is_check[i] = 1; // 숫자 i를 사용 중이라고 표시(Lock)
            
            back(k + 1);     // 다음 칸(k+1)을 채우러 들어감
            
            is_check[i] = 0; // 재귀가 끝나고 돌아오면, 숫자 i를 다시 쓸 수 있게 반납(Unlock)
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    back(0);
    return 0;
}