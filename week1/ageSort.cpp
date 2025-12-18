//BOJ 10814

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, string>> v; // 동적할당 시에는 push_back을, 미리 크기 설정을 하면 인덱스로 직접 접근을 해야함.

    for (int i = 0; i < n; i++)
    {
        int age;
        string name;

        cin >> age >> name;
        v.push_back({age,name});
    }
    stable_sort(v.begin(),v.end(),[](const pair<int,string>& a, const pair<int,string>& b){ //람다함수 사용 그러나 구조체를 쓰면 더 가독성이 좋아짐
        return a.first < b.first;
    });

    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << ' ' << v[i].second <<'\n';
    }
    return 0;
}