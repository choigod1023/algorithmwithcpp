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
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq; // greater로 설정해야 오름차순 우선순위 큐로 설정

    if (n == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    int current_sum = 0;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        pq.push(input);
    }
    int total = 0;
    while (pq.size() > 1)
    {
        int el1 = pq.top();
        pq.pop();
        int el2 = pq.top();
        pq.pop();
        current_sum = el1 + el2;
        total += current_sum;
        pq.push(current_sum);
    }

    cout << total << '\n';
}