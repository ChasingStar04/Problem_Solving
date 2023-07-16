//어차피 스택에 한 번 들어오고 한 번 나가면 O(n)이다.
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long cnt = 0;
    stack<pair<int, int>> stk;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int num;

        cin>>num;
        int same = 0;
        while (!stk.empty())
        {
            if (stk.top().first>num)
            {
                cnt++;
                break;
            }
            else if (stk.top().first==num)
            {
                same = stk.top().second;
                cnt += (long long)stk.top().second;
                stk.pop();
            }
            else
            {
                cnt += (long long)stk.top().second;
                stk.pop();
            }
        }
        stk.push({num, same+1});
    }
    cout<<cnt;

    return 0;
}

/*
//풀이 2. 처음에 떠올린, 굳이굳이 어렵게 푼 풀이. 스택에 있는 자신보다 큰 사람의 수를 구하기 위해 벡터로 스택을 구현하고, 이분 탐색을 썼다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stk;

int FindUpperIndex(int num)
{
    int s = 0, e = stk.size();
    while (s<e)
    {
        int mid = (s+e)/2;
        if (stk[mid]<=num)
            e = mid;
        else
            s = mid+1;
    }

    return (e>0 ? e-1 : 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long cnt = 0;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int num;

        cin>>num;
        if (!stk.empty())
            cnt += (long long)stk.size()-FindUpperIndex(num);
        //cout<<'('<<stk.size()<<' '<<cnt<<") ";
        while (!stk.empty() && stk.back()<num)
            stk.pop_back();
        stk.push_back(num);
    }
    cout<<cnt;

    return 0;
}
*/
