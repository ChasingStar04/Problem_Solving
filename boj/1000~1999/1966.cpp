/*
들어온 숫자 배열을 (숫자, 번째)의 형태로 순서대로 큐에 넣습니다.

큐 안의 원소들 중 최댓값(우선순위가 제일 높은 값)을 찾고,
(숫자=최댓값) 인 원소가 나올 때까지 제일 앞의 원소를 뒤로 넘깁니다.
찾는 원소가 나올 때까지 최댓값을 찾고 뒤로 넘기는 과정을 반복합니다.
*/
#include <iostream>

using namespace std;

struct ii
{
    int index;
    int imp;
}  print_queue[10000];
int fr, re;

void push_queue(ii a)
{
    print_queue[re++] = a;
    return;
}

int main()
{
    int t;

    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, m, cnt = 0;
        fr = 0, re = 0;
        cin>>n>>m;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            push_queue({j, a});
        }
        while(fr<re)
        {
            int imp = print_queue[fr].imp;
            for(int j=fr; j<re; j++)
                imp = max(imp, print_queue[j].imp);
            if(imp==print_queue[fr].imp)
            {
                cnt++;
                if(print_queue[fr].index==m)
                {
                    cout<<cnt<<'\n';
                    break;
                }
                fr++;
            }
            else
            {
                push_queue(print_queue[fr]);
                fr++;
            }
        }
    }
    return 0;
}
