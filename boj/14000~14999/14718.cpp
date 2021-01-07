/*
사람 수가 100명으로 제한되어있으므로
스탯이 될 수 있는 경우의수도 100*100*100 밖에 안됩니다.
모든 경우의 수를 돌려서 구합니다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct Data
{
    int num;  //병사 번호
    int stat;  //스탯
};

int enemy[100][3];
Data str[100], dex[100], intel[100];  //힘 민첩 지능

bool cmp(Data a, Data b)
{
    return a.stat<b.stat;
}

int Func(int n, int m)
{
    int sstat, dstat, istat;
    int cnt = 0;
    int minstat = 0x3f3f3f3f;

    for(int i=0; i<n; i++)
    {
        sstat = str[i].stat;
        for(int j=0; j<n; j++)
        {
            dstat = dex[j].stat;
            cnt = 0;
            for(int k=0; k<n; k++)
            {
                istat = intel[k].stat;
                int num = intel[k].num;

                if(sstat>=enemy[num][0] && dstat>=enemy[num][1] && istat>=enemy[num][2])
                {
                    cnt++;
                    if(cnt>=m && sstat+dstat+istat<minstat)
                        minstat = sstat+dstat+istat;
                }
            }
        }
    }

    return minstat;
}

int main()
{
    int n, m;

    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>enemy[i][0];
        str[i] = {i, enemy[i][0]};
        cin>>enemy[i][1];
        dex[i] = {i, enemy[i][1]};
        cin>>enemy[i][2];
        intel[i] = {i, enemy[i][2]};
    }

    sort(str, str+n, cmp);
    sort(dex, dex+n, cmp);
    sort(intel, intel+n, cmp);

    cout<<Func(n, m);

    return 0;
}
