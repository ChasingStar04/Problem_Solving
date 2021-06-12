//가장 왼쪽의 알파벳보다 작거나 같으면 왼쪽에 놓고, 아니라면 오른쪽에 놓습니다.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;

    cin>>t;
    for (int i=0; i<t; i++)
    {
        int n;
        vector<char> v;

        cin>>n;
        for (int j=0; j<n; j++)
        {
            char input;
            
            cin>>input;
            if (v.empty() || v[0]>=input)
                v.insert(v.begin(), input);
            else
                v.push_back(input);
        }

        for (char &j : v)
            cout<<j;
        cout<<'\n';
    }

    return 0;
}
