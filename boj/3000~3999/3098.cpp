/*
i와 j가 연결되어있고 j와 k가 연결되어있고 i와 k가 연결되어 있지 않다면
i와 k를 연결해주면서 cnt를 증가시킵니다.
만약 cnt가 n*(n-1)/2이 되었다면 모든 점들이 서로 연결된것입니다.
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int edge[51][51];
int n, m;

int main()
{
    int day = 0, cnt = 0;
    vector<int> arr;
    memset(edge, -1, sizeof(edge));

    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        edge[a][b] = 0;
        edge[b][a] = 0;
        cnt++;
    }

    while (true)
    {
        int todaycnt = 0;
        day++;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(edge[i][j]!=-1 && edge[i][j]<day && i!=j)
                {
                    for(int k=1; k<=n; k++)
                    {
                        if(i!=k && j!=k && edge[j][k]!=-1 && edge[j][k]<day && edge[i][k]==-1)
                        {
                            todaycnt++;
                            edge[i][k] = day;
                            edge[k][i] = day;
                        }
                    }
                }
            }
        }
        arr.push_back(todaycnt);
        cnt += todaycnt;
        if(cnt==n*(n-1)/2)
            break;
    }

    cout<<day<<'\n';
    for(int i=0; i<day; i++)
        cout<<arr[i]<<'\n';
    
    return 0;
}
