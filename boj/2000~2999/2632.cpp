//피자A의 모든 가능한 합을 adds에 저장해놓은 뒤,
//피자B의 모든 가능합 합에 대해 알맞은 값이 있는지 adds에서 lower_bound와 upper_bound를 이용하여 확인합니다.
//시간복잡도는 O(n^2 log n) 입니다. => 피자A 값 저장 n^2 + 피자B 값 계산 m^m * 이분탐색 log n (n와 m의 최댓값이 같으므로 똑같이 n으로 통일)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w, m, n;
    int a[1010] = {0};
    int b[1010] = {0};
    vector<int> adds;
    long long result = 0;

    cin>>w;
    cin>>m>>n;
    for (int i=0; i<m; i++)
        cin>>a[i];
    for (int i=0; i<n; i++)
        cin>>b[i];
    
    int acnt = 0;
    for (int i=0; i<m; i++)
    {
        int cnt = 0, j = i;
        int e = (m+i-1)%m;
        while (j!=e)
        {
            cnt += a[j];
            adds.push_back(cnt);
            j = (j+1)%m;
        }
        acnt += a[i];
    }
    adds.push_back(acnt); //a의 모든 조각을 고른 경우
    adds.push_back(0);
    sort(adds.begin(), adds.end());

    int bcnt = 0;
    for (int i=0; i<n; i++)
    {
        int cnt = 0, j = i;
        int e = (n+i-1)%n;
        while (j!=e)
        {
            cnt += b[j];
            result += upper_bound(adds.begin(), adds.end(), w-cnt)-lower_bound(adds.begin(), adds.end(), w-cnt);
            j = (j+1)%n;
        }
        bcnt += b[i];
    }
    result += upper_bound(adds.begin(), adds.end(), w-bcnt)-lower_bound(adds.begin(), adds.end(), w-bcnt); //b의 모든 조각을 고른 경우
    result += upper_bound(adds.begin(), adds.end(), w)-lower_bound(adds.begin(), adds.end(), w); //b을 고르지 않은 경우
    cout<<result;   

    return 0;
}
