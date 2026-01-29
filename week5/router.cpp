#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
long long int mid, high, low;
vector<long long int> v;
long long int dist(int mid) //거리 재는 함수
{
    long long int cnt = 0;
    int install = v[0]; // 항상 v[0]에 설치
    cnt++;
    for (int i = 1; i < v.size(); i++)
    {
        if(abs(install-v[i])>=mid){ // 설치한 장소와 거리 비교해서 mid값보다 크면 cnt++ 
            install = v[i];
            cnt++;
        }
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
        long long int slash_cnt = dist(mid); //mid값을 연산시킨 값을 slash_cnt라 하자. 공유기 개수가 맞는지 체크해야함.
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

    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int res = bin(c);
}