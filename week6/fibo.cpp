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
    int n;
    cin >> n;
    vector<long long int> dp(n + 1); //동적으로 크기 설정 
    dp[0]=0;
    dp[1] = 1;
    for (long long int i = 2; i <= n; i++) // 2부터 시작해서 N까지
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout << dp[n] << '\n';
}