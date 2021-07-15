//음식을 선택하는 경우의 수가 2^15=32768개 밖에 안되므로, 완전 탐색 돌리면 쉽게 풀 수 있습니다.
//재귀함수로 완전탐색을 돌려줍니다.
//지금까지 선택한 음식은 비트마스크로 보내줬습니다. 문자열을 이용해도 됩니다.
#include <iostream>

using namespace std;

int n;
int arr[15][5];
int mini[4];
int result = 0x3f3f3f3f; //최소비용
int foods; //선택한 음식(비트마스크)

void Solve(int p, int f, int s, int v, int cost, int check, int a) //check => 지금까지 선택한 음식들(비트마스크), a => 선택해야 하는 음식
{
    if (p>=mini[0] && f>=mini[1] && s>=mini[2] && v>=mini[3])
    {
        if (cost<=result)
        {
            result = cost;
            foods = max(check, foods);
        }
        return;
    }
    else if (a>=n) return;

    Solve(p, f, s, v, cost, check, a+1);
    Solve(p+arr[a][0], f+arr[a][1], s+arr[a][2], v+arr[a][3], cost+arr[a][4], check|(1<<(n-a)), a+1);
    return;
}

int main()
{
    cin>>n;
    for (int i=0; i<4; i++)
        cin>>mini[i];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<5; j++)
            cin>>arr[i][j];
    }

    Solve(0, 0, 0, 0, 0, 0, 0);
    if (result!=0x3f3f3f3f)
    {
        cout<<result<<'\n';
        for (int i=0; i<n; i++)
        {
            if (foods&(1<<(n-i)))
                cout<<i+1<<' ';
        }
    }
    else
        cout<<-1;
    
    return 0;
}
