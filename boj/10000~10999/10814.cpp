/*
안정 정렬을 해야 해서 stl의 stable_sort를 사용했습니다.
안정 정렬에는 버블정렬, 삽입정렬, 병합정렬 등이 있습니다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct Data
{
    int old;
    char name[110];
}  people[100000];

bool cmp(Data a, Data b)
{
    return a.old<b.old;
}

int main()
{
    int n;

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>people[i].old>>people[i].name;
    
    stable_sort(people, people+n, cmp);
    for(int i=0; i<n; i++)
        cout<<people[i].old<<' '<<people[i].name<<'\n';
    
    return 0;
}
