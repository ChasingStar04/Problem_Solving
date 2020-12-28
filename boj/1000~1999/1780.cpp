/*
문제에 쓰여있는 그~대로 짜면 됩니다.
종이가 모두 같은 수로 되어있는지 확인하고, 같으면 카운트 증가, 다르면 9등분한 후 앞의 과정을 반복합니다.
*/
#include <iostream>

using namespace std;

int map[2200][2200];
int count[3];

bool Check(int x1, int x2, int y1, int y2)
{
    int checknum = map[y1][x1];
    for(int i=y1; i<y2; i++)
    {
        for(int j=x1; j<x2; j++)
        {
            if(map[i][j]!=checknum)
                return false;
        }
    }
    return true;
}

void Divide(int x1, int x2, int y1, int y2)
{
    if(Check(x1, x2, y1, y2))
        count[map[y1][x1]+1]++;
    else
    {
        int x_one_third = (x2-x1)/3;
        int y_one_third = (y2-y1)/3;

        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
                Divide(x1+i*x_one_third, x1+(i+1)*x_one_third, y1+j*y_one_third, y1+(j+1)*y_one_third);
        }
    }
    return;
}

int main()
{
    int n;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>map[i][j];
    }

    Divide(0, n, 0, n);
    for(int i=0; i<3; i++)
        cout<<count[i]<<'\n';
    
    return 0;
}
