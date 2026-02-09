#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector <int>> input(n,vector <int>(3)); //RGB 입력받을 이차원배열
    vector<vector<int>> dp(n,vector <int>(3)); // DP 이차원배열
    for (int i = 0; i < n; i++)
    {
        for (int color = 0; color < 3; color++)
        {
            cin >> input[i][color];
        }
    }
    dp[0] = input[0]; //첫항 입력
    for (int i = 1; i < n; i++)
    {
        // 점화식 : dp[i][color] = 이전에 칠한 비용의 최솟값 + 현재 색칠하려는 색의 비용
            dp[i][0] = input[i][0] + min(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = input[i][1] + min(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = input[i][2] + min(dp[i-1][0],dp[i-1][1]);
    }
    int m = min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
    cout << m << '\n';
    
}