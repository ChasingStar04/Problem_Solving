/*
한번 자를 때마다 초콜릿 조각이 1개씩 늘어나므로
n*m개 조각으로 쪼갤려면 n*m-1번 쪼개야 합니다
*/
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", n*m-1);
    return 0;
}