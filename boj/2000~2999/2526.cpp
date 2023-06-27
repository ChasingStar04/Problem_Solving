#include <iostream>

using namespace std;

int main()
{
    int n, p;
    int table[100] = {0};

    cin>>n>>p;

    int num = (n*n)%p, c = 1;
    while (table[num]==0)
    {
        table[num] = c;
        num = (num*n)%p;
        c++;
    }

    cout<<c-table[num];

    return 0;
}
