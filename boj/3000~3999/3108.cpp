/*
변끼리 서로 겹치는 직사각형들을 한 그룹으로 묶고, 그룹의 개수를 구합니다.
(그룹의 개수)-1 이 문제의 답입니다.

그룹을 만드는 방법은,
새로운 직사각형이 들어오면 이전에 들어온 모든 직사각형들과 각각 겹치는지 검사합니다.
겹쳤을 때, 새 직사각형이 그룹에 포함되어있지 않다면 겹친 직사각형의 그룹에 새 직사각형을 포합시키고,
이미 그룹에 포함되어있다면 겹친 직사각형의 그룹에 포함되어있는 직사각형들을 새 직사각형의 그룹으로 옮겨줍니다.

직사각형끼리 겹치는지 판단하는 방법은 코드의 Contact 함수를 참고해주세요.
*/
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;
};

struct Square
{
    Point p1;
    Point p2;
} squ[1010];

vector<int> group[1010];

/*
//처음에 썼던 잘못된 Contact 알고리즘. 반례 찾느라 고생 좀 했습니다...
int InLineOut(Square s, Point p)
{
    if (p.x>s.p1.x && p.x<s.p2.x && p.y>s.p1.y && p.y<s.p2.y)
        return 0; //in
    else if (p.x>=s.p1.x && p.x<=s.p2.x && p.y>=s.p1.y && p.y<=s.p2.y)
        return 1; //line
    else
        return 2; //out
}

bool Contact(Square a, Square b) //<<문제의 원인 ((1, 0), (2, 3)), ((0, 1), (3, 2))
{
    int arr[3] = {0}; //[in, line, out]

    arr[InLineOut(a, b.p1)]++;
    arr[InLineOut(a, b.p2)]++;
    arr[InLineOut(a, {b.p1.x, b.p2.y})]++;
    arr[InLineOut(a, {b.p2.x, b.p1.y})]++;
    if (arr[0]!=4 && arr[2]!=4)
        return true;

    arr[0] = 0, arr[1] = 0, arr[2] = 0;
    arr[InLineOut(b, a.p1)]++;
    arr[InLineOut(b, a.p2)]++;
    arr[InLineOut(b, {a.p1.x, a.p2.y})]++;
    arr[InLineOut(b, {a.p2.x, a.p1.y})]++;
    if (arr[0]!=4 && arr[2]!=4)
        return true;

    return false;
}
*/

bool Contact(Square a, Square b)
{
    if (a.p1.x>b.p1.x && a.p1.y>b.p1.y && a.p2.x<b.p2.x && a.p2.y<b.p2.y) //a in b
        return false;
    if (b.p1.x>a.p1.x && b.p1.y>a.p1.y && b.p2.x<a.p2.x && b.p2.y<a.p2.y) //b in a
        return false;
    if (a.p1.x>b.p2.x || a.p1.y>b.p2.y || b.p1.x>a.p2.x || b.p1.y>a.p2.y)
        return false;
    return true;
}


int main()
{
    int n, cnt = 0;

    cin>>n;

    //squ[0] = {{0, 0}, {0, 0}};
    group[0].push_back(0);
    for (int i=1; i<=n; i++)
    {
        cin>>squ[i].p1.x>>squ[i].p1.y>>squ[i].p2.x>>squ[i].p2.y;

        int has_group = -1;
        for (int j=0; j<i; j++)
        {
            for (int& k : group[j])
            {
                if (Contact(squ[i], squ[k]))
                {
                    if (has_group!=-1)
                    {
                        for (int& l : group[j])
                            group[has_group].push_back(l);
                        group[j].clear();
                    }
                    else
                    {
                        group[j].push_back(i);
                        has_group = j;
                    }

                    break;
                }
            }
        }
        if (has_group==-1)
            group[i].push_back(i);
    }

    for (auto& i : group)
    {
        if (i.size()>0)
            cnt++;
    }
    cout<<cnt-1;

    return 0;
}
