#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int mid, high, low;
vector<int> v;

int bin(int target)
{
    while (low<=high) //low랑 high가 같거나 넘어서버리면 하극상이므로 종료
    {
        mid = low + (high - low) / 2; // mid 값 초기화. high-low를 먼저 계산하고 low를 넣는 이유는 절댓값
        if (v[mid] == target)
        {
            return 1;
        }
        else if (v[mid] < target) // 타겟이 미드값보다 크면 아래를 올려서 범위를 줄여야함.
        {
            low = mid + 1;
        }
        else if (v[mid] > target) // 타겟이 미드값보다 작으면 위를 내려서 범위를 줄여야함.
        {
            high = mid - 1;
        }
    }
    return 0;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;

        high = v.size() - 1;
        low = 0;
        int res = bin(input);
        cout << res << '\n';
    }
}