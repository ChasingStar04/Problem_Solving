//https://chasingstar.tistory.com/26
#include <iostream>

using namespace std;

int maxtable[50000000];
int numtable[50000000];

int Func(int x, int y)
{
    if (x>y)
        return 0;
	if (x==1 && y<50000000)
		return maxtable[y];
	
    int a = 1, i = 0;

    while (a*2-1<=y)
    {
        a *= 2;
        i++;
    }
    a--;

    return max(Func(x, a-1), i + Func(max(x, a+1)-a, y-a));
}

void SetTable()
{
    int a = 1, p = 0;

    for (int i=1; i<50000000; i++)
    {
        if (a*2-1<=i)
        {
            a *= 2;
            p++;
        }
        if (i==a-1)
            numtable[i] = p;
        else
            numtable[i] = numtable[a-1] + numtable[i-(a-1)];
        maxtable[i] = max(numtable[i], maxtable[i-1]);

        int nt = numtable[i];
        int mt = maxtable[i];
    }
    return;
}

int main()
{
    int t;

    SetTable();

    cin>>t;
    for (int i=0; i<t; i++)
    {
        int x, y, n = 1;

        cin>>x>>y;
        cout<<Func(x, y)<<'\n';
    }

    return 0;
}
