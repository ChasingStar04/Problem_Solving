/*
정렬할 원소의 최대값이 10000밖에 안되므로, 카운팅 정렬을 사용하면 빠르게 정렬할 수 있으나
메모리 제한 때문에 카운팅 정렬의 원리만을 이용했습니다.

입력받은 수를 카운트 배열에 카운트하고
1을 count[1]번 출력 -> 2를 count[2]번 출력 -> ... -> n을 count[n]번 출력 합니다.
또 시간 초과를 막기위해 cin/cout 대신 scanf/printf를 사용했습니다.
*/
#include <iostream>

using namespace std;

int count[10001];

int main()
{
    int n, num = 0, cptr = 1;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        count[num]++;
    }
    
    for(int i=0; i<n; i++)
    {
        while(count[cptr]==0)  cptr++;
        printf("%d\n", cptr);
        count[cptr]--;
    }
    
    return 0;
}
