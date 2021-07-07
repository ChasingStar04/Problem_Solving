/*
BFS로 풀 수 있습니다.
숫자를 넘겨줄 때, 배열로 넘겨주거나 n자리의 숫자로 넘겨주면 visit 테이블을 사용하기 불편하므로
그 숫자가 n자리의 숫자로 만들 수 있는 몇 번째 순열인지를 계산하여 그걸로 넘겨줍니다.
*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Data
{
    int order;
    int cost;
};

int n, k;

int NumToOrder(int num)
{
    bool arr[9] = {0};
    int a = 1;
    int order = 0;

    for (int i=1; i<=n; i++)
    {
        int now = num%10;
        int cnt = 0;
        for (int j=1; j<now; j++)
        {
            if (arr[j])
                cnt++;
        }
        order += cnt*a;

        arr[now] = true;
        num /= 10;
        a *= i;
    }
    return order;
}

int OrderToNum(int order)
{
    bool arr[9] = {0};
    int a = 1;
    int num = 0;

    for (int i=2; i<n; i++)
        a *= i;
    for (int i=n-1; i>=0; i--)
    {
        int th = order/a;
        int cnt = 0;
        for (int j=1; j<=n; j++)
        {
            if (!arr[j] && th==cnt)
            {
                num = num*10 + j;
                arr[j] = true;
                order %= a;
                break;
            }
            else if (!arr[j])
                cnt++;
        }
        if (i>0)
            a /= i;
    }
    return num;
}

int BFS(int num)
{
    queue<Data> que;
    bool visit[41000];

    que.push({NumToOrder(num), 0});
    visit[NumToOrder(num)] = true;
    while (!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        if (tmp.order==0)
            return tmp.cost;
        
        int number = OrderToNum(tmp.order);
        int arr[9] = {0};
        for (int i=n-1; i>=0; i--)
        {
            arr[i] = number%10;
            number /= 10;
        }
        
        int nn;
        for (int i=0; i<n-k+1; i++)
        {
            nn = 0;
            for (int j=0; j<i; j++) //뒤집기전
                nn = nn*10 + arr[j];
            for (int j=i+k-1; j>=i; j--) //뒤집
                nn = nn*10 + arr[j];
            for (int j=i+k; j<n; j++) //뒤집은후
                nn = nn*10 + arr[j];
            
            if (!visit[NumToOrder(nn)])
            {
                que.push({NumToOrder(nn), tmp.cost+1});
                visit[NumToOrder(nn)] = true;
            }
        }
    }
    
    return -1;
}

int main()
{
    int num = 0;
    
    cin>>n>>k;
    for (int i=0; i<n; i++)
    {
        int tmp;
        cin>>tmp;
        num = num*10 + tmp;
    }
    cout<<BFS(num);
    
    return 0;
}
