#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> qu;
    int n,k;
    vector<int> re;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        qu.push(i);
    }
    while(!qu.empty()){
        int data;
        int idx = k%(qu.size())==0? k : k%(qu.size());
        for(int i=0;i<idx-1;i++){
            data = qu.front();
            qu.pop();
            qu.push(data);
        }
        data = qu.front();
        qu.pop();
        re.push_back(data);
    }
    cout << "<";
    for(int i=0;i<n;i++){
        cout << re[i] << (i==n-1? ">" : ", ");

    }
    return 0;
}