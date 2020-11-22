/*
dp[a][b][c][d] = 1번 사람이 a개, 2번 사람이 b개, 3번 사람이 c개를 먹었고, 마지막으로 d번 사람이 먹었을 때 최소 회전
로 정의하여 dp 테이블을 채워줍니다.
*/
#include <iostream>
#include <cstring>

using namespace std;

int dp[101][101][101][3];  //[아빠가먹은요리수][엄마가먹은요리수][현이가먹은요리수][마지막으로먹은사람]
int food[3][101];  //먹고싶어하는 요리
int pi[3];;  //먹고싶어하는 요리의 갯수
int n;

int Location(int num, int p)  //위치를 아빠기준으로 바꿈
{
    return (num+n-(n/3*p))%n==0 ? n : (num+n-(n/3*p))%n; 
}

int Distance(int a, int b)  //요리 사이의 거리를 반환
{
    int dist = a>b ? a-b : b-a;
    return min(dist, n-dist);
}

int Func()  //for문 돌려서 dp함수 호출
{
    int c[3] = {0};
    int o[3] = {0};

    for(c[0]=0; c[0]<=pi[0]; c[0]++)
    {
        for(c[1]=0; c[1]<=pi[1]; c[1]++)
        {
            for(c[2]=0; c[2]<=pi[2]; c[2]++)
            {
                for(int i=0; i<3; i++)
                {
                    if(c[i]==0)
                        continue;
                    
                    o[0] = c[0], o[1] = c[1], o[2] = c[2];
                    o[i]--;

                    dp[c[0]][c[1]][c[2]][i] = min(dp[c[0]][c[1]][c[2]][i], dp[o[0]][o[1]][o[2]][0]+Distance(food[i][c[i]], food[0][o[0]]));
                    dp[c[0]][c[1]][c[2]][i] = min(dp[c[0]][c[1]][c[2]][i], dp[o[0]][o[1]][o[2]][1]+Distance(food[i][c[i]], food[1][o[1]]));
                    dp[c[0]][c[1]][c[2]][i] = min(dp[c[0]][c[1]][c[2]][i], dp[o[0]][o[1]][o[2]][2]+Distance(food[i][c[i]], food[2][o[2]]));
                }
            }
        }
    }

    return min(dp[pi[0]][pi[1]][pi[2]][0], min(dp[pi[0]][pi[1]][pi[2]][1], dp[pi[0]][pi[1]][pi[2]][2]));
}

int main()
{
    cin>>n;

    for(int i=0; i<3; i++)
    {
        int tmp;
        cin>>pi[i];
        for(int j=1; j<=pi[i]; j++)
        {
            cin>>tmp;
            food[i][j] = Location(tmp, i);
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    food[0][0] = 1;
    food[1][0] = 1;
    food[2][0] = 1;
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;
    dp[0][0][0][2] = 0;
    cout<<Func();

    return 0;
}
