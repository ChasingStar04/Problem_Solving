//퍼즐을 2차원 배열이 아닌 문자열을 이용하여 관리하고, bfs를 이용합니다.
#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

struct Data
{
    string str;
    int move;
};

int bfs(string str)
{
    int dire[4] = {1, -1, 3, -3};
    queue<Data> que;
    set<string> visit;

    que.push({str, 0});
    visit.insert(str);
    while (!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        if (tmp.str=="123456780")
            return tmp.move;
        
        int zero = tmp.str.find('0');
        string s;
        for (int i=0; i<4; i++)
        {
            int nextzero = zero+dire[i];
            if (nextzero<0 || nextzero>=9 || (zero%3==2 && i==0) || (zero%3==0 && i==1))
                continue;
            s = tmp.str;
            swap(s[zero], s[nextzero]);
            if (visit.count(s)==0)
            {
                que.push({s, tmp.move+1});
                visit.insert(s);
            }
        }
    }

    return -1;
}

int main()
{
    string input = "";
    for (int i=0; i<9; i++)
    {
        int n;
        cin>>n;
        input += to_string(n);
    }

    cout<<bfs(input);

    return 0;
}
