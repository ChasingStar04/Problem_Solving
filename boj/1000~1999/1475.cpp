#include <iostream>

using namespace std;

int main()
{
    char input[10] = {0};
    int cnt[10] = {0}, res = 0;
    
    cin>>input;
    for (int i=0; i<10; i++)
    {
        if (input[i]=='9') input[i]='6';
        if (input[i]>='0' && input[i]<='9')
        {
            cnt[input[i]-'0']++;
            res = max(res, (input[i]=='6' ? (cnt[input[i]-'0']-1)/2+1 : cnt[input[i]-'0']));
        }
    }
    cout<<res;

    return 0;
}
