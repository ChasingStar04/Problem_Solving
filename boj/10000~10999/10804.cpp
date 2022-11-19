//후입선출 구조인 스택을 이용하여 구간을 뒤집습니다.
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int arr[21] = {0};

    for (int i=1; i<=20; i++)
        arr[i] = i;
    
    stack<int> stk;
    for (int i=0; i<10; i++)
    {
        int s, e;
        cin>>s>>e;

        for (int j=s; j<=e; j++)
            stk.push(arr[j]);
        for (int j=s; j<=e; j++)
        {
            arr[j] = stk.top();
            stk.pop();
        }        
    }

    for (int i=1; i<=20; i++)
        cout<<arr[i]<<' ';
    
    return 0;
}
