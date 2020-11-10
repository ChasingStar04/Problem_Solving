//정렬의 편의성을 위해 char 자료형에 입력받아서 정렬합니다
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(char a, char b)
{
    return a>b;
}

int main()
{
    char num[12] = {0};

    cin>>num;
    sort(num, num+strlen(num), cmp);
    cout<<num;

    return 0;
}
