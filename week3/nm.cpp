#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int m, n;
int arr[10];
int is_check[10];

void back(int k)
{
    if (k == m) //조건의 열의 끝에 도달했을 때
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' '; //해당하는 열에 대한 내용이 반복문에 m개만큼 있을 테니, 이를 출력하겠지.
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) //깊이 탐색(i는 우리가 탐색할 숫자 카드들... 이 반복문은 행을 나타낸다.)
    {
        if (!is_check[i]) // 현재 이 숫자 카드를 사용중인가? i가 1인데, is_check[1]이 true라면 1 1이 조합되려고 하는 상태가 아니겠는가?
        {
            arr[k] = i; //출력 배열에 숫자 카드를 넣는다.
            is_check[i] = 1; //해당 숫자 카드를 현재 행에서 사용하고 있음을 나타냄.
            back(k + 1); // 재귀를 실행하여 다음 "열"에 대한 조건을 탐색하는거지.
            is_check[i] = 0; //내가 사용한 행에 대한 숫자 카드를 다 썼다면 반납하기.
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