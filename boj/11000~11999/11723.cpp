//비트마스크를 이용합니다.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int s = 0;
    int m;

    cin>>m;
    for (int i=0; i<m; i++)
    {
        string input;
        cin>>input;
        
        if (input=="add")
        {
            int num;
            cin>>num;
            s |= (1<<num);
        }
        else if (input=="remove")
        {
            int num;
            cin>>num;
            s &= ~(1<<num);
        }
        else if (input=="check")
        {
            int num;
            cin>>num;
            if (s&(1<<num)) cout<<"1\n";
            else cout<<"0\n";
        }
        else if (input=="toggle")
        {
            int num;
            cin>>num;
            s ^= (1<<num);
        }
        else if (input=="all")
            s = ~0;
        else if (input=="empty")
            s = 0;
    }

    return 0;
}
