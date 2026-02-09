#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int cnt = 0; cnt < t; cnt++)
    {
        int n;
        cin >> n;
        vector< int> dp(n + 1); // 동적으로 크기 설정
        dp[1] = 1; //1에서의 경우의 수 1 하나
        dp[2] = 2; //2에서의 경우의 수 1+1, 2
        dp[3] = 4; //3에서의 경우의 수 1+1+1, 2+1, 1+2, 3
        if (n >= 4)
        {
            for (int i = 4; i <= n; i++) // 4부터 시작해서 N까지
            {
                dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]); //마지막에 1을 더한 경우의 수, 2를 더한 경우의 수, 3를 더한 경우의 수를 모두 더한 값이 dp[i]의 값
            }
            cout << dp[n] << '\n';
        }
        else
            cout << dp[n] << '\n';
    }
}