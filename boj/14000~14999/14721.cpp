//브루트 포싱. rss는 long long으로 구합시다.
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int student[110][2] = {0};

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>student[i][0]>>student[i][1];
    
    long long minrss = 0x3f3f3f3f3f3f3f3fLL;

    int a, b;
    for (int i=1; i<=100; i++)
    {
        for (int j=1; j<=100; j++)
        {
            long long rss = 0;
            for (int k=0; k<n; k++)
            {
                long long srss = (long long)abs(student[k][1]-(student[k][0]*i+j)) * (long long)abs(student[k][1]-(student[k][0]*i+j));
                rss += srss;
            }
            if (rss<minrss)
            {
                minrss = rss;
                a = i;
                b = j;
            }
        }
    }

    cout<<a<<' '<<b;
    
    return 0;
}
