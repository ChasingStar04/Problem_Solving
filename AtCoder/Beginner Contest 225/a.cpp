//AC
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;

    if (s[0]!=s[1] && s[1]!=s[2] && s[0]!=s[2])
        cout<<6;
    else if (s[0]==s[1] && s[1]==s[2] && s[0]==s[2])
        cout<<1;
    else
        cout<<3;
    
    return 0;
}
