#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> st;

    int n, target;
    vector<int> t;
    vector<char> re;
    cin >> n;

    //생각이 지저분해져서 gemini에게 도움을 요청함... 주석은 gemini가 나의 생각을 바로잡은 부분
    int cnt=1;
    for (int i = 1; i <= n; i++)
    {
        int input;
        cin >> input;
        t.push_back(input);
    }
    for (int i = 0; i < n; i++)
    {
        target = t[i];
        if (st.empty() || target >= st.top())
        {
            for (;cnt <= target; cnt++) // cnt를 1로 계속 초기화하는 실수를 했다. 스택에 계속 1부터 쌓이니까 문제가 생김
            {
                st.push(cnt);
                re.push_back('+');
            }
        }
        while (!st.empty())
        {
            if (target == st.top())
            {
                st.pop();
                re.push_back('-');
                break;
            }
            else if (target < st.top()) // 이 문제의 핵심이라고 할 수 있는 부분. 어차피 타겟보다 스택의 top이 크다면 top을 먼저 pop해야하기 때문에 NO조건임!!
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    for (int i = 0; i < re.size(); i++) //부호의 사이즈를 n으로 하면 안됐음. 동적으로 할당한 벡터이니 size() 메소드를 이용했다면 동적으로 length 처리도 되었을 터.
    {
        cout << re[i] << '\n';
    }
}