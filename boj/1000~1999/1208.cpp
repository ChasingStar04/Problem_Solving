//https://chasingstar.tistory.com/25
#include <iostream>

#define ZERO 4000000
using namespace std;

long long table[8000010];

int main()
{
    int n, s;

    cin>>n>>s;

    for (int i=0; i<n; i++)
    {
        int num;
        cin>>num;
        
        if (num<0)
        {
            for (int j=0; j<=8000000; j++)
            {
                if (table[j])
                    table[j+num] += table[j];
            }
            table[ZERO+num]++;
        }
        else
        {
            for (int j=8000000; j>=0; j--)
            {
                if (table[j])
                    table[j+num] += table[j];
            }
            table[ZERO+num]++;
        }
    }

    cout<<table[ZERO+s];

    return 0;
}
