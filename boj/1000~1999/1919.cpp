//각 알파벳 개수 카운트 -> 카운트의 차 만큼 +
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char a[1010], b[1010];
int cnta[26], cntb[26];
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a;
    cin>>b;

    for (int i=0; i<strlen(a); i++)
        cnta[a[i]-'a']++;
    for (int i=0; i<strlen(b); i++)
        cntb[b[i]-'a']++;
    
    for (int i=0; i<26; i++)
        ans += abs(cnta[i]-cntb[i]);
    cout<<ans;

    return 0;
}
