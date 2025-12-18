//BOJ 10818

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,min=0,max=0;
    cin >> n;
    cin >> min;
    max=min;
    for(int i=0;i<n-1;i++){
        int a;
        cin >>a;
        if(a>max) max=a;
        if(a<min) min=a;
    }
    cout << min << ' ' << max << '\n';
    return 0;

}ㄷ