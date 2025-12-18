//BOJ 11650

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(2)); //pair를 사용해서 열길이2로 할당해도 됨
    for(int y=0;y<n;y++){
        for (int x=0;x<2;x++){
            cin >> v[y][x];
        }
    }
    sort(v.begin(),v.end());
    for(int y=0;y<n;y++){
        for (int x=0;x<2;x++){
            cout << v[y][x] <<' ';
        }
        cout << '\n';

    }
    return 0;
}