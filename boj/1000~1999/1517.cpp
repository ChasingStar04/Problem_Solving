/*
풀이 1. 합병 정렬을 이용한 풀이

합병 정렬을 할 때 오른쪽 배열의 숫자를 새로운 정렬할 배열에 넣는다면
그 숫자는 왼쪽 배열에 남아있는 수의 개수만끔 땅겨진 것이므로
왼쪽 배열에 남아있는 수의 개수만끔 swap했다고 볼 수 있습니다.
이와같은 아이디어로 오른쪽 배열의 숫자를 새로운 정렬할 배열에 넣을 때 왼쪽 배열에 남아있는 수의 개수를 더합니다.
*/
#include <iostream>

using namespace std;

int arr[500010], tmp[500010];
long long result;

void Merge(int left, int mid, int right)
{
    int i = left;
    int j = mid+1;
    int idx = 0;

    while (i<=mid || j<=right)
    {
        if (i<=mid && (j>right || arr[i]<=arr[j]))
            tmp[idx++] = arr[i++];
        else
        {
            tmp[idx++] = arr[j++];
            result += (long long)mid-i+1;
        }
    }
    
    for (int k=left; k<=right; k++) arr[k] = tmp[k-left];
    return;
}

void MergeSort(int left, int right)
{
    if (left<right)
    {
        int mid = (left+right)/2;
        MergeSort(left, mid);
        MergeSort(mid+1, right);
        Merge(left, mid, right);
    }
    return;
}

int main()
{
    int n;

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    MergeSort(0, n-1);
    cout<<result;

    return 0;
}

/*
풀이 2. 세그먼트 트리를 이용한 풀이

버블 정렬의 swap 횟수는
각각의 숫자에서 자신보다 앞에 있는 숫자들 중 자신보다 큰 숫자의 개수의 합입니다.
예를들어서 {7, 5, 2, 3, 6, 1, 4} 라는 배열이 있다면
자신보다 앞에 있는 숫자들 중 자신보다 큰 숫자의 개수는 {0, 1, 2, 2, 1, 5, 3} 이므로
swap 횟수는 1+2+2+1+5+3=14번 입니다.

들어온 배열을 내림차순으로, 만약 숫자가 같다면 더 뒤에 들어온 순으로 정렬한 후
세그먼트 트리를 만들어 자신의 원래 인덱스 앞의 인덱스들 중 마킹되어있는 인덱스의 개수를 구하고
자신의 원래 인덱스에 마킹합니다.

#include <iostream>
#include <algorithm>

using namespace std;

struct Data
{
    int num;
    int th;
} arr[500010];

int tree[1100000];

void Update(int start, int end, int node, int index, int diff)
{
    if(start>index || end<index)  return;
    tree[node] += diff;
    if(start==end)  return;

    int mid = (start+end)/2;
    Update(start, mid, node*2, index, diff);
    Update(mid+1, end, node*2+1, index, diff);
}

int Count(int start, int end, int node, int left, int right)
{
    if(start>right || end<left)  return 0;
    if(left<=start && end<=right)  return tree[node];

    int mid = (start+end)/2;
    return Count(start, mid, node*2, left, right) + Count(mid+1, end, node*2+1, left, right);
}

bool cmp(Data a, Data b)
{
    if(a.num!=b.num)
        return a.num>b.num;
    else
        return a.th>b.th;
}

int main()
{
    int n;
    long long result = 0;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].num;
        arr[i].th = i;
    }

    sort(arr, arr+n, cmp);
    for(int i=0; i<n; i++)
    {
        result += Count(0, 500000, 1, 0, arr[i].th-1);
        Update(0, 500000, 1, arr[i].th, 1);
    }

    cout<<result;

    return 0;
}
*/
