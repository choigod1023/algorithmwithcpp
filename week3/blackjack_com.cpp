//Gemini가 만든 블랙잭 코드. 순열에서의 중복을 방지하기 위해 조합으로 생성.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int n, m;
vector<int> nums, sums;
int is_check[100];
int sum = 0;
// start_idx: 이전에 고른 카드 다음부터 탐색하기 위한 변수
void back(int k, int start_idx) 
{
    if (k == 3)
    {
        if(sum <= m)
            sums.push_back(sum);
        return;
    }

    // i는 0부터가 아니라 start_idx부터 시작! (앞쪽 카드는 다시 안 봄)
    for (int i = start_idx; i < n; i++) 
    {
        // 조합이므로 is_check 배열이 필요 없음 (항상 뒤쪽만 보니까 중복 선택 안 함)
        
        sum += nums[i]; 
        
        // 다음 재귀에서는 현재 카드(i)의 '다음 카드(i+1)'부터 보라고 전달
        back(k + 1, i + 1); 
        
        sum -= nums[i]; // 복구 로직은 동일하게 훌륭함!
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    back(0,0);

    sort(sums.begin(),sums.end(),[](int i,int j){return j<i;}); //내림차순 정렬
    cout << sums[0];
    return 0;
}