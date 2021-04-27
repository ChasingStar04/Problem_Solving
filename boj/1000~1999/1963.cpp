//에라토스테네스의 체를 이용하여 1000~9999까지의 소수를 미리 구해 놓고 bfs를 이용합니다.
#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct Data
{
    string str;
    int cnt;
};

bool not_prime[10000];

void SetPrime()
{
    for (int i=2; i*i<10000; i++)
    {
        for (int j=2; i*j<10000; j++)
            not_prime[i*j] = true;
    }
    return;
}

void bfs(string start, string end)
{
    queue<Data> que;
    set<string> visit;

    que.push({start, 0});
    visit.insert(start);
    while (!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        if (tmp.str==end)
        {
            cout<<tmp.cnt<<'\n';
            return;
        }

        string s;
        for (int i=0; i<4; i++)
        {
            for (int j=0; j<10; j++)
            {
                s = tmp.str;
                s[i] = j+'0';
                if (!not_prime[stoi(s)] && stoi(s)>=1000 && visit.count(s)==0)
                {
                    que.push({s, tmp.cnt+1});
                    visit.insert(s);
                }
            }
        }
    }
    
    cout<<"Impossible\n";
    return;
}

int main()
{
    int t;

    SetPrime();
    cin>>t;
    for (int i=0; i<t; i++)
    {
        string start, end;
        cin>>start>>end;

        bfs(start, end);
    }

    return 0;
}
