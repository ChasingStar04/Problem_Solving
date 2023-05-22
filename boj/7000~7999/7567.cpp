#include <iostream>

using namespace std;

int main()
{
    char str[55] = {0};
    char last = ' ';
    int res = 0;

    cin>>str;
    for (char &c : str)
    {
        if (c!='(' && c!=')') break;
        if (c==last) res += 5;
        else res += 10;

        last = c;
    }
    cout<<res;

    return 0;
}
