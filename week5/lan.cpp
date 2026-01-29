#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
using namespace std;
long long int mid, high, low;
vector<long long int> v;
long long int wood(int mid) //자르는 함수
{
    long long int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cnt += (v[i] / mid);
    }
    return cnt;
}

long long int bin(int target_cnt)
{
    high = v.back();
    low = 1;
    long long int max=0;

    while (low <= high) // low랑 high가 같거나 넘어서버리면 하극상이므로 종료
    {
        mid = low + (high - low) / 2; // mid 값 초기화. high-low를 먼저 계산하고 low를 넣는 이유는 오버플로우 방지.
        long long int slash_cnt = wood(mid); //mid값을 연산시킨 값을 slash_cnt라 하자
        if (target_cnt <= slash_cnt) // slash_cnt가 우리가 목표로하는 값보다 크다? 개수는 충분하니, 저점을 올려서 길이를 늘려보는거지.
        {
            max= max<mid ? mid:max; //최대 비교
            low = mid+1; // 저점을 올리기
        }
        else {
            //그렇지 않다면? 길이가 부족하다는거니까 고점을 낮춰야함.
            high = mid - 1;
        }
    }
    cout << max << '\n';
    return 0;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int res = bin(n);
}