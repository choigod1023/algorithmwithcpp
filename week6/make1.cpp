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
    vector<int> dp(n + 1); //동적으로 크기 설정 
    dp[1] = 0; //항상 1일 때는 횟수가 0임을 초기화해두기.
    for (int i = 2; i <= n; i++) // 2부터 시작해서 N까지
    {
        //먼저 1로 빼었을 때의 횟수를 기본으로 1 늘려서 저장
        dp[i] = dp[i - 1] + 1;

        //2로 나누어떨어질때
        if (i % 2 == 0)
        {
            //1로 뺐을 때의 횟수와, 이전에 2로 나누었을 때의 값에다가 횟수를 1 증가시킨것 중에 어떤 것이 더 최솟값인지를 비교
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        //3으로 나누어떨어질때
        if (i % 3 == 0)
        {
            //1로 뺐을 때의 횟수와, 이전에 3로 나누었을 때의 값에다가 횟수를 1 증가시킨것 중에 어떤 것이 더 최솟값인지를 비교
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }
    cout << dp[n] << '\n';
}