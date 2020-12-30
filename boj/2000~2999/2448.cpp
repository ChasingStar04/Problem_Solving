/*
|  *   |
| * *  |
|***** | <<를 기본 도형으로 잡고 분할 탐색 하였습니다.
*/
#include <iostream>
#include <cstring>

using namespace std;

char arr[4000][7000];

void Fill(int x1, int x2, int y1, int y2)
{
    arr[y1][x1+2] = '*';
    arr[y1+1][x1+1] = '*';
    arr[y1+1][x1+3] = '*';
    for(int i=x1; i<x2-1; i++)
        arr[y1+2][i] = '*';
    return;
}

void Divide(int x1, int x2, int y1, int y2)
{
    if(y2-y1==3)
        Fill(x1, x2, y1, y2);  //배열의 해당 공간을 규칙으로 채움
    else
    {
        int x_1quarter = x1+(x2-x1)/4;
        int x_2quarter = x1+(x2-x1)/4*2;
        int x_3quarter = x1+(x2-x1)/4*3;
        int y_half = (y1+y2)/2;

        Divide(x_1quarter, x_3quarter, y1, y_half);
        Divide(x1, x_2quarter, y_half, y2);
        Divide(x_2quarter, x2, y_half, y2);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;  //n->y축크기, m=x축크기

    cin>>n;
    
    m = n/3*6;
    memset(arr, ' ', sizeof(arr));
    Divide(0, m, 0, n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<arr[i][j];
        cout<<'\n';
    }

    return 0;
}
