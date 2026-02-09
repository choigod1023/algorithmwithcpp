#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
vector<long long int> heap={0};
long long int n;
long long int idx = 1;

void up_heap() //맨하위 자손부터 루트까지 올라오면서 자손이 부모보다 크면 스왑
{
    for(long long j=idx;j>1;j/=2)
    if (heap[j] > heap[j / 2])
    {
        swap(heap[j/2],heap[j]);
    }
}

void down_heap(){ // 맨위 루트부터 자손까지 내려가면서 부모가 left/right보다 작으면 스왑
    long long cur =1; // cur은 부모
    while(cur*2 < heap.size()){
        long long left = cur*2; // left는 자식의 왼쪽 요소
        long long right = cur*2+1; //right는 자식의 오른쪽 요소
        long long target = left; // 일단 left가 크다고 가정
        if(right<heap.size() && heap[right]> heap[left]){ // right가 존재하고, right의 값이 left보다 크면 스왑 타겟을 변경
            target = right;
        }
        if(heap[cur]>=heap[target]) break; // 부모가 자식보다 크면 종료
        swap(heap[cur], heap[target]);
        cur = target;
        
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (long long int i = 0; i < n; i++)
    {
        long long int input;
        cin >> input;
        // 언제 업힙을 하고 언제 다운힙을 하는가?
        // 인풋넣을때 업힙(맨 뒤에 넣으니까), pop할때 요소를 루트에 박고 다운힙
        if (input) //input이 0이 아닐 때
        {
            heap.push_back(input); //힙의 맨 뒤에 넣기
            up_heap();
            idx++;
        }
        else
        {

            if (heap.size() >1)
            {
                long long int max = heap[1];
                cout << max << '\n';
                heap[1] = heap.back();
                heap.pop_back();
                down_heap();
                idx--;
            }
            else
            {
                cout << 0 << '\n';
            }
        }
    }
}
