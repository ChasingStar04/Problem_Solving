//개수 테이블을 이용한다. a는 +1. b는 -1. 0이 아니면 false.
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, table[26] = {0};
    char a[1010], b[1010];

    cin>>n;
    for (int i=0; i<n; i++)
    {
        memset(table, 0, sizeof(table));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        cin>>a>>b;
        for (int j=0; j<strlen(a); j++)
            table[a[j]-'a']++;
        for (int j=0; j<strlen(b); j++)
            table[b[j]-'a']--;
        
        bool flag = true;
        for (int j=0; j<26; j++)
        {
            if (table[j]!=0)
            {
                flag = false;
                break;
            }
        }

        if (flag) cout<<"Possible\n";
        else cout<<"Impossible\n";
    }

    return 0;
}
