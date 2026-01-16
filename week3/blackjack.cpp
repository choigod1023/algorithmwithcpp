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
void back(int k)
{
    if (k == 3) // 조건의 열의 끝에 도달했을 때
    {
        if(sum <= m) // 블랙잭 조건이 동적으로 변경됨.
            sums.push_back(sum);
        return;
    }

    for (int i = 0; i < n; i++) // 깊이 탐색(i는 우리가 탐색할 숫자 카드들... 이 반복문은 행을 나타낸다.)
    {
        if (!is_check[i]) // 현재 이 숫자 카드를 사용중인가? i가 1인데, is_check[1]이 true라면 1 1이 조합되려고 하는 상태가 아니겠는가?
        {
            sum += nums[i]; //합치기 위해서 변수에 덧셈
            is_check[i] = 1; // 해당 숫자 카드를 현재 행에서 사용하고 있음을 나타냄.
            back(k + 1);     // 재귀를 실행하여 다음 "열"에 대한 조건을 탐색하는거지.
            sum -= nums[i]; //<중요> sum에 있는 변수를 초기화할 때에는 0이 아니라 뺄셈으로 빼줘야함. 그 이유는 내가 덧셈한 내용으로 열의 끝에 돌아온 이후로 다른 행으로의 탐색을 시작해야하기 때문에...
            is_check[i] = 0; // 내가 사용한 행에 대한 숫자 카드를 다 썼다면 반납하기.
        }
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

    back(0);

    sort(sums.begin(),sums.end(),[](int i,int j){return j<i;}); //내림차순 정렬
    cout << sums[0];
    return 0;
}