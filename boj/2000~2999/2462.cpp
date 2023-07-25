//m과 n이 모두 2 이상이면 모든 칸을 지날 수 있습니다. 구현이 정말 까다로웠던 문제.
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

struct yxc
{
    int y;
    int x;
    int c;
};

bool visit[110][110][2];
bool joong_bock, cant_move;
vector<yxc> v;

bool CantMove(yxc a, yxc b)
{
    if (((a.x)+(a.y))%2==0 && a.c==0)
    {
        if (b.y==a.y && b.x==a.x && b.c==1) return true;
        else if (b.y==a.y && b.x==a.x-1 && b.c==1) return true;
        else if (b.y==a.y && b.x==a.x+1 && b.c==0) return true;
        else if (b.y==a.y-1 && b.x==a.x) return true;
        else return false;
    }
    else if (((a.x)+(a.y))%2==0 && a.c==1)
    {
        if (b.y==a.y && b.x==a.x && b.c==0) return true;
        else if (b.y==a.y && b.x==a.x-1 && b.c==1) return true;
        else if (b.y==a.y && b.x==a.x+1 && b.c==0) return true;
        else if (b.y==a.y+1 && b.x==a.x) return true;
        else return false;
    }
    else if (((a.x)+(a.y))%2==1 && a.c==0)
    {
        if (b.y==a.y && b.x==a.x && b.c==1) return true;
        else if (b.y==a.y-1 && b.x==a.x && b.c==1) return true;
        else if (b.y==a.y+1 && b.x==a.x && b.c==0) return true;
        else if (b.y==a.y && b.x==a.x-1) return true;
        else return false;
    }
    else if (((a.x)+(a.y))%2==1 && a.c==1)
    {
        if (b.y==a.y && b.x==a.x && b.c==0) return true;
        else if (b.y==a.y-1 && b.x==a.x && b.c==1) return true;
        else if (b.y==a.y+1 && b.x==a.x && b.c==0) return true;
        else if (b.y==a.y && b.x==a.x+1) return true;
        else return false;
    }
    else
        return false;
}

void Print(int y, int x, int c)
{
    cout<<y<<' '<<x<<' '<<c<<'\n';

    if (visit[y][x][c])
        joong_bock = true;
    else
    {
        visit[y][x][c] = true;
        v.push_back({y, x, c});
    }
    if (!v.empty() && CantMove(v.back(), {y, x, c}))
        cant_move = true;
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;

    cin>>m>>n;
    if (m==1)
    {
        if (n==1)
        {
            cout<<"2\n";
            Print(1, 1, 0);
            Print(1, 1, 1);
        }
        else if (n<=3)
        {
            cout<<"3\n";
            Print(1, 1, 0);
            Print(1, 1, 1);
            Print(1, 2, 0);
        }
        else
        {
            cout<<"4\n";
            Print(1, 2, 1);
            Print(1, 3, 0);
            Print(1, 4, 0);
            Print(1, 3, 1);
        }
    }
    else if (n==1)
    {
        if (m==2)
        {
            cout<<"3\n";
            Print(1, 1, 1);
            Print(2, 1, 0);
            Print(2, 1, 1);
        }
        else
        {
            cout<<"4\n";
            Print(1, 1, 1);
            Print(2, 1, 0);
            Print(3, 1, 0);
            Print(2, 1, 1);
        }
    }
    else if (m%2==0)
    {
        cout<<m*n*2<<'\n';
        for (int i=1; i<=m; i++)
        {
            if (i%2==0)
            {
                for (int j=n; j>=2; j--)
                {
                    if ((i+j)%2==0)
                    {
                        Print(i, j, 0);
                        Print(i, j, 1);
                    }
                    else
                    {
                        Print(i, j, 1);
                        Print(i, j, 0);
                    }
                }
            }
            else
            {
                for (int j=2; j<=n; j++)
                {
                    Print(i, j, 0);
                    Print(i, j, 1);
                }
            }
        }
        for (int i=m; i>=1; i--)
        {
            Print(i, 1, 1);
            Print(i, 1, 0);
        }
    }
    else if (n%2==0)
    {
        cout<<m*n*2<<'\n';
        for (int i=1; i<=n; i++)
        {
            if (i%2==0)
            {
                for (int j=m; j>=2; j--)
                {
                    if ((i+j)%2==0)
                    {
                        Print(j, i, 1);
                        Print(j, i, 0);
                    }
                    else
                    {
                        Print(j, i, 0);
                        Print(j, i, 1);
                    }
                }
            }
            else
            {
                for (int j=2; j<=m; j++)
                {
                    Print(j, i, 0);
                    Print(j, i, 1);
                }
            }
        }
        for (int i=n; i>=2; i--)
        {
            Print(1, i, 1);
            Print(1, i, 0);
        }
        Print(1, 1, 0);
        Print(1, 1, 1);
    }
    else
    {
        cout<<m*n*2<<'\n';
        for (int i=1; i<m/2; i++)
        {
            if (i%2==0)
            {
                for (int j=n; j>=2; j--)
                {
                    if ((i+j)%2==0)
                    {
                        Print(i, j, 0);
                        Print(i, j, 1);
                    }
                    else
                    {
                        Print(i, j, 1);
                        Print(i, j, 0);
                    }
                }
            }
            else
            {
                for (int j=2; j<=n; j++)
                {
                    Print(i, j, 0);
                    Print(i, j, 1);
                }
            }
        }
        if ((m/2)%2==0)
        {
            Print(m/2, n, 1);
            Print((m/2)+1, n, 0);
            Print(m/2, n, 0);
            for (int i=n-1; i>2; i-=2)
            {
                Print((m/2), i, 0);
                Print((m/2), i, 1);
                Print((m/2)+1, i, 1);
                Print((m/2)+1, i, 0);
                Print((m/2)+1, i-1, 0);
                Print((m/2), i-1, 1);
                Print((m/2), i-1, 0);
            }
            Print((m/2), 2, 0);
            Print((m/2), 2, 1);
            Print((m/2)+1, 2, 0);
            Print((m/2)+1, 2, 1);
            for (int i=2; i<=n; i++)
            {
                Print((m/2)+2, i, 0);
                if (i%2==1)
                    Print((m/2)+1, i, 1);
                Print((m/2)+2, i, 1);
            }
        }
        else
        {
            Print((m/2), 2, 0);
            Print((m/2)+1, 2, 0);
            Print((m/2), 2, 1);
            for (int i=3; i<n; i+=2)
            {
                Print((m/2), i, 0);
                Print((m/2), i, 1);
                Print((m/2)+1, i, 0);
                Print((m/2)+1, i, 1);
                Print((m/2)+1, i+1, 0);
                Print((m/2), i+1, 0);
                Print((m/2), i+1, 1);
            }
            Print((m/2), n, 0);
            Print((m/2), n, 1);
            Print((m/2)+1, n, 0);
            Print((m/2)+1, n, 1);
            for (int i=n; i>=2; i--)
            {
                if (i%2==0)
                {
                    Print((m/2)+2, i, 1);
                    Print((m/2)+1, i, 1);
                    Print((m/2)+2, i, 0);
                }
                else
                {
                    Print((m/2)+2, i, 0);
                    Print((m/2)+2, i, 1);
                }
            }
        }
        for (int i=m/2+3; i<=m; i++)
        {
            if (i%2==1)
            {
                for (int j=n; j>=2; j--)
                {
                    if ((i+j)%2==0)
                    {
                        Print(i, j, 0);
                        Print(i, j, 1);
                    }
                    else
                    {
                        Print(i, j, 1);
                        Print(i, j, 0);
                    }
                }
            }
            else
            {
                for (int j=2; j<=n; j++)
                {
                    Print(i, j, 0);
                    Print(i, j, 1);
                }
            }
        }
        for (int i=m; i>=1; i--)
        {
            Print(i, 1, 1);
            Print(i, 1, 0);
        }
    }
    
    if (joong_bock)
        cout<<"Jung Bock!!!!!\n";
    if (v.size()!=m*n*2)
        cout<<"Not All!!!!!\n";
    if (cant_move)
        cout<<"Cant Move!!!!!\n";
    
    return 0;
}
