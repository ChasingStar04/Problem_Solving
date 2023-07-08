/*
복잡해 보이지만 정렬 문제일 뿐이었다.
개미굴이 출력되는 순서는 사전순 정렬이고, 곂치는 부분을 생략하는 작업만 고려하면 된다.

근데 트라이 라는 게 있었네
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;


bool cmp(vector<string> a, vector<string> b)
{
    int minsize = min(a.size(), b.size());

    for (int i=0; i<minsize; i++)
    {
        if (a[i]!=b[i])
            return a[i]<b[i];
    }
    return a.size()<b.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    vector<string> v[1010];

    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>k;
        for (int j=0; j<k; j++)
        {
            string s;
            cin>>s;
            v[i].push_back(s);
        }
    }

    sort(v, v+n, cmp);
    stack<string> stk;
    vector<string> same;
    for (int i=0; i<n; i++)
    {
        int erp = v[i].size(); //erase_pointer
        for (int j=0; j<min(same.size(), v[i].size()); j++)
        {
            if (same[j]!=v[i][j])
            {
                erp = j;
                break;
            }
        }
        int old_same_size = same.size();
        for (int j=erp; j<old_same_size; j++)
            same.pop_back();

        for (int j=same.size(); j<v[i].size(); j++)
        {
            for (int k=0; k<j; k++)
                cout<<"--";
            cout<<v[i][j]<<'\n';
            same.push_back(v[i][j]);
        }
    }

    return 0;
}
