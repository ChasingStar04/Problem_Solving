//stl sort를 활용하여 풀었습니다.
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Str
{
    char word[55];
}  str1[20010];

bool cmp(Str a, Str b)
{
    if(strlen(a.word)!=strlen(b.word))
        return strlen(a.word)<strlen(b.word);
    else
        return strcmp(a.word, b.word)<0;
}

int main()
{
    int n;

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>str1[i].word;
    
    sort(str1, str1+n, cmp);
    for(int i=0; i<n; i++)
    {
        if(strcmp(str1[i].word, str1[i+1].word))
            cout<<str1[i].word<<'\n';
    }
    return 0;
}
