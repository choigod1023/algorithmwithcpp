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

    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    vector<int> weight(n+1);
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= k; w++) //w는 배낭 무게, weight[i]는 물건의 무게
        {
            if(weight[i]<=w){ // 내 배낭 무게보다 물건의 무게가 작거나 같을 때만 점화식에 넣기. 아니라면 배낭을 목표 무게까지 증가시키기.
            // 점화식 : dp[i][w] = 최댓값(안넣었을때, 넣었을 때(원래 가치 + 원래 dp(현재 무게에서 배낭 무게를 뺀 값))
                dp[i][w] = max(dp[i-1][w],v[i]+dp[i-1][w-weight[i]]);
            }
            else{

                //만약 배낭 무겝돠 물건의 무게가 커서 못넣는 상태라면 원래 항을 그대로 넣어야겠지.
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    cout << dp[n][k] << '\n';
}