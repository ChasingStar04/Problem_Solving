/*
다음 칸으로 올라갈 수 있으면 올라가는 그리디한 방식이 가장 빨리 올라가는 방법입니다.
막대기를 움직이고 올라가는 부분은 무식하게 구현했습니다.
*/
#include <iostream>

using namespace std;

int f[3010][2]; //(floor) [0] -> 시작점, [1] -> 끝점
int dict[3010]; //이동 방향
int n, l;

bool CanUp(int now_floor)
{
    if (f[now_floor][0]<f[now_floor+1][0])
        return f[now_floor+1][0]<=f[now_floor][1];
    else if (f[now_floor][0]==f[now_floor+1][0])
        return true;
    else
        return f[now_floor][0]<=f[now_floor+1][1];
}

void MoveFloor(int now_floor, int time)
{
    int onestep = (l-(f[now_floor][1]-f[now_floor][0]))*2;

    if (onestep==0)
        return;
    
    int movecount = time%onestep;
    for (int i=0; i<movecount; i++)
    {
        f[now_floor][0] += dict[now_floor];
        f[now_floor][1] += dict[now_floor];
        if (f[now_floor][0]==0 || f[now_floor][1]==l)
            dict[now_floor] *= -1;
    }

    return;
}

int main()
{
    cin>>n>>l;

    for (int i=0; i<n; i++)
    {
        int len, d;

        cin>>len>>d;
        if (d==0)
        {
            f[i][0] = 0;
            f[i][1] = len;
            dict[i] = 1;
        }
        else
        {
            f[i][0] = l-len;
            f[i][1] = l;
            dict[i] = -1;
        }
    }

    int now_floor = 0, time = 0;
    while (now_floor<n-1)
    {
        if (CanUp(now_floor))
        {
            now_floor += 1;
            if (now_floor<n-1)
                MoveFloor(now_floor+1, time);
        }
        else
        {
            MoveFloor(now_floor, 1);
            MoveFloor(now_floor+1, 1);
            time++;
        }
    }

    cout<<time;

    return 0;
}
