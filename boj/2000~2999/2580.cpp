//dfs를 이용해 해결할 수 있습니다.
//오직 하나의 경우만을 출력해야 하므로 가능한 경우를 찾으면 출력한 후 dfs를 종료하도록 코딩해줍니다.
#include <iostream>
#include <vector>

using namespace std;

struct Data
{
    int x;
    int y;
};

int board[9][9];
vector<Data> blank;

bool Can(Data loca, int num)
{
    for (int i=0; i<9; i++)
    {
        if (board[loca.y][i]==num)
            return false;
        if (board[i][loca.x]==num)
            return false;
    }

    int x1 = (loca.x/3)*3, x2 = (loca.x/3+1)*3;
    int y1 = (loca.y/3)*3, y2 = (loca.y/3+1)*3;

    for (int i=y1; i<y2; i++)
    {
        for (int j=x1; j<x2; j++)
        {
            if (board[i][j]==num)
                return false;
        }
    }

    return true;
}

void Print()
{
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
            cout<<board[i][j]<<' ';
        cout<<'\n';
    }
    return;
}

bool dfs(int n)
{
    if (n==blank.size())
    {
        Print();
        return true;
    }

    for (int i=1; i<=9; i++)
    {
        if (Can(blank[n], i))
        {
            board[blank[n].y][blank[n].x] = i;
            if (dfs(n+1))
                return true;
            board[blank[n].y][blank[n].x] = 0;
        }
    }

    return false;
}

int main()
{
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            cin>>board[i][j];
            if (board[i][j]==0)
                blank.push_back({j, i});
        }
    }

    for (int i=1; i<=9; i++)
    {
        if (Can(blank[0], i))
        {
            board[blank[0].y][blank[0].x] = i;
            dfs(1);
            board[blank[0].y][blank[0].x] = 0;
        }
    }

    return 0;
}
