//B배열에서 만들 수 있는 부배열의 합을 미리 다 구해 저장한 후
//A배열의 부배열의 합을 구하면서 A와 B의 부배열의 합이 t인 경우를 이진 탐색으로 찾습니다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int narr[1010] = {0};
    int marr[1010] = {0};
    vector<long long> adds;
    int t, n, m;
    long long result = 0;

    cin>>t;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>narr[i];
    cin>>m;
    for (int i=0; i<m; i++)
        cin>>marr[i];
    
    for (int i=0; i<m; i++)
    {
        long long sum = 0;
        for (int j=i; j<m; j++)
        {
            sum += (long long)marr[j];
            adds.push_back(sum);
        }
    }
    sort(adds.begin(), adds.end());

    for (int i=0; i<n; i++)
    {
        long long sum = 0;
        for (int j=i; j<n; j++)
        {
            sum += (long long)narr[j];
            result += upper_bound(adds.begin(), adds.end(), (long long)t-sum)-lower_bound(adds.begin(), adds.end(), (long long)t-sum);
        }
    }

    cout<<result;

    return 0;
}
