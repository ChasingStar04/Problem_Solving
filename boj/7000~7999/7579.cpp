/*
접근) n과 c가 작으므로 이들을 기준을 하는 편이 나을 것입니다.

n*c <= 10000 이므로 c의 합을 기준으로 한 dp테이블을 만들어 구합니다.
table[i] = i코스트 이하로 얻을 수 있는 최대 메모리
한 앱이 중복으로 더해지는 것을 막기 위해 j를 역순으로 돌린 것이 포인트(line 28)
*/
#include <iostream>
#include <cstring>

using namespace std;

int table[11000];
int mem[110], cst[110];

int main()
{
    int n, m;

    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>mem[i];
    for (int i=0; i<n; i++)
        cin>>cst[i];
    
    for (int i=0; i<n; i++)
    {
        for (int j=10000; j>=0; j--)
            table[j+cst[i]] = max(table[j+cst[i]], table[j]+mem[i]);
    }

    for (int j=0; j<=10000; j++)
    {
        if (table[j]>=m)
        {
            cout<<j;
            break;
        }
    }

    return 0;
}
