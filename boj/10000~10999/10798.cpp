//문제대로 잘 구현합니다.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str[5];

    for (int i=0; i<5; i++)
        cin>>str[i];
    
    for (int i=0; i<15; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (str[j].length()>i)
                cout<<str[j][i];
        }
    }
    cout<<'\n';

    return 0;
}
