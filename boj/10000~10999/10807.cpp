#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, v, table[210] = {0};
    cin>>n;

    for (int i=0; i<n; i++)
    {
        int num;
        cin>>num;
        table[num+100]++;
    }
    cin>>v;

    cout<<table[v+100];
    
    return 0;
}
