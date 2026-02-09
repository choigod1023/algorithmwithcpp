#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    int cnt=0;
    cin >> n>>k;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int input;
        cin >> input;
        pq.push(input);
    }
    while(k>0){
        int coin = pq.top();

        pq.pop();
        int mok = k/coin;
        if(mok>0){
            cnt+=mok;
            k-=(mok*coin);
        }
        
    }

        cout << cnt << '\n';

}