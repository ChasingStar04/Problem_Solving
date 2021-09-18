//n에서 0이 출력되는 횟수 = (n-1에서 0이 출력되는 횟수) + (n-2에서 0이 출력되는 횟수) 입니다. 1의 경우에도 마찬가지입니다.
//n이 0일때와 1일때의 출력 횟수는 이미 알고 있으므로, 위 식으로 2~40까지의 값을 미리 구해 둡니다.
#include <iostream>

using namespace std;

int main()
{
    int table[41][2] = {0};    
    int t;

    table[0][0] = 1;
    table[1][1] = 1;
    for (int i=2; i<=40; i++)
    {
        table[i][0] = table[i-1][0]+table[i-2][0];
        table[i][1] = table[i-1][1]+table[i-2][1];
    }

    cin>>t;
    for (int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        cout<<table[n][0]<<' '<<table[n][1]<<'\n';
    }

    return 0;
}
