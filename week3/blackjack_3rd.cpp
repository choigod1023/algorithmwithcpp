//군대 개짬찌일때 알고리즘 공부하던 시절 만든 블랙잭입니다. 3차원 반복문으로 만들었어요. 재귀+백트래킹과의 차이점을 느껴보세요.

#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    int arr[100000]={0,};
    int n,m;
    int temp;
    cin >>n>>m;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    for (int i = 0;i<n-2;i++){
        for(int j = i+1;j<n-1;j++){
            for (int k=j+1;k<n;k++){
                temp = arr[i]+arr[j]+arr[k];
                if (temp <=m && temp>=sum ){
                    sum = temp;
                }
            }
        }
    }
    cout << sum;
    return 0;
}