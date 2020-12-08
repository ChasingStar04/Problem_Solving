/*
postorder에서 루트 노드가 항상 마지막에 위치한다는 점을 이용해 inorder에서 루트 노드의 위치를 구합니다.
그 후 루트 노드 출력 -> 왼쪽 서브트리 탐색 -> 오른쪽 서브트리 탐색 합니다.
*/
#include <iostream>

using namespace std;

int inorder[100010];
int postorder[100010];
int n;


int FindIndex(int s, int e, int key, int arr[])
{
    for(int i=s; i<=e; i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;  //ide에서 워닝 뜨는게 불편해서 넣었습니다. 없어도 됩니다.
}

void PreOrder(int in_s, int in_e, int post_s, int post_e)
{
    if(in_s>in_e || post_s>post_e)
        return;

    int root_index_in_inorder = FindIndex(in_s, in_e, postorder[post_e], inorder);
    int right_index_int_postorder = (root_index_in_inorder!=in_e ?
        FindIndex(post_s, post_e, inorder[root_index_in_inorder+1], postorder) : post_e);

    cout<<inorder[root_index_in_inorder]<<' ';
    PreOrder(in_s, root_index_in_inorder-1, post_s, right_index_int_postorder-1);  //왼쪽 서브트리
    PreOrder(root_index_in_inorder+1, in_e, right_index_int_postorder, post_e-1);  //오른쪽 서브트리
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>inorder[i];
    for(int i=0; i<n; i++)
        cin>>postorder[i];
    
    PreOrder(0, n-1, 0, n-1);

    return 0;
}
