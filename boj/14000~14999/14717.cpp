/*
상대방의 패가 될 수 있는 모든 경우에 수에 대해 이길지 질지를 판단한 후
(이기는 횟수)/(이기는 횟수+이기지 못하는 횟수) 를 계산하여 이길 확률을 구합니다.
*/
#include <iostream>

using namespace std;

//c=영학이카드, d=상대카드
bool IsWin(int c1, int c2, int d1, int d2)
{
    int cp = (c1==c2 ? c1*10 : (c1+c2)%10);
    int dp = (d1==d2 ? d1*10 : (d1+d2)%10);

    return cp>dp;
}

int main()
{
    int card[20] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10};
    int c1, c2;

    cin>>c1>>c2;
    
    card[(c1-1)*2] = 0;
    card[(c2-1)*2+1] = 0;

    int win = 0, notwin = 0;
    for(int i=0; i<20; i++)
    {
        if(card[i]==0)
            continue;
        for(int j=0; j<20; j++)
        {
            if(card[j]==0 || i==j)
                continue;
            if(IsWin(c1, c2, card[i], card[j]))
                win++;
            else
                notwin++;
        }
    }

    printf("%.3lf", (double)win/(win+notwin));

    return 0;
}
