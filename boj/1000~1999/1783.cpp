//n과 m이 충분히 클 경우, 방문할 수 있는 최대 칸은 m-2개입니다.
//n과 m이 작은 경우에만 따로 처리 해줍니다.
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    if (n==1)
        cout<<1;
    else if (n==2)
        cout<<min((m+1)/2, 4);
    else if (m<=6)
        cout<<min(m, 4);
    else
        cout<<m-2;
    
    return 0;
}
