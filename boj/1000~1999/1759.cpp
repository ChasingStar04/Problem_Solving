//dfs를 이용하여 l자리 암호를 만든 후, 조건을 충족하는지 검사하고 충족한다면 벡터에 추가합니다.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int l, c;
char arr[15];
vector<string> password;

void dfs(string s, int idx)
{
    if(s.length()==l)
    {
        int ja = 0, mo = 0;
        for(char& c : s)
        {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                mo++;
            else
                ja++;
        }
        if (mo>=1 && ja>=2)
            password.push_back(s);
        return;
    }

    for (int i=idx+1; i<c; i++)
        dfs(s+arr[i], i);
    return;
}

int main()
{
    cin>>l>>c;
    for (int i=0; i<c; i++)
        cin>>arr[i];

    sort(arr, arr+c);
    for (int i=0; i<c; i++)
    {
        string s;
        s += arr[i];
        dfs(s, i);
    }

    for (auto& s : password)
        cout<<s<<'\n';

    return 0;
}
