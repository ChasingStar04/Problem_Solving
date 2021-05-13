/*
새 막대기가 들어오면 자신보다 뒤에 있으면서 키가 작거나 같은 막대기는 가려지게 됩니다.
이것을 스택으로 구현할 수 있습니다.

새 막대기가 들어오면 자신보다 키가 큰 막대기가 나올 때까지 스택에서 pop하고
새 막대기를 스택에 추가합니다.
모든 막대기가 들어온 후 스택의 size가 문제의 답이 됩니다.
*/
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    stack<int> stk;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int h;
        cin>>h;
        while (!stk.empty() && stk.top()<=h)
            stk.pop();
        stk.push(h);
    }
    cout<<stk.size();

    return 0;
}
