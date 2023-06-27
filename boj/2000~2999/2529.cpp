/*
자신보다 뒤에있는 숫자들 중, 자신보다 확실히 큰 숫자의 개수와 확실히 작은 숫자의 개수를 고려하면 됩니다.
자신보다 앞에있는 숫자는 중복 검사 과정에서 알아서 고려됩니다.
*/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    int up[11] = {0}, down[11] = {0};
    char inq[11] = {0};
    int table[10] = {0};

    cin>>k;
    for (int i=0; i<k; i++)
        cin>>inq[i];
    
    for (int i=k-1; i>=0; i--)
    {
        if (inq[i]=='<')
            up[i] = up[i+1]+1;
        else
            down[i] = down[i+1]+1;
    }

    for (int i=0; i<=k; i++)
    {
        int counter = 0;
        for (int j=9; j>=0; j--)
        {
            if (table[j]==0)
            {
                if (counter>=up[i])
                {
                    cout<<j;
                    table[j] = 1;
                    break;
                }
                counter++;
            }
        }
    }

    cout<<'\n';
    memset(table, 0, sizeof(table));
    for (int i=0; i<=k; i++)
    {
        int counter = 0;
        for (int j=0; j<=9; j++)
        {
            if (table[j]==0)
            {
                if (counter>=down[i])
                {
                    cout<<j;
                    table[j] = 1;
                    break;
                }
                counter++;
            }
        }
    }

    return 0;
}
