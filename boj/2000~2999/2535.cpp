#include <iostream>
#include <algorithm>

using namespace std;

struct Student
{
    int country;
    int num;
    int score;
} s[110];

bool cmp(Student a, Student b) {return a.score>b.score;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int arr[110] = {0};

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>s[i].country>>s[i].num>>s[i].score;
    
    sort(s, s+n, cmp);
    int cnt = 0;
    for (Student &i : s)
    {
        if (cnt>=3) break;
        if (arr[i.country]<2)
        {
            cout<<i.country<<' '<<i.num<<'\n';
            arr[i.country]++;
            cnt++;
        }
    }

    return 0;
}
