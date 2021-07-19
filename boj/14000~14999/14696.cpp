//그냥 문제대로 구현하면 됩니다.
#include <iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int a, b;
        int arr[4][2] = {0};

        cin>>a;
        for (int j=0; j<a; j++)
        {
            int input;
            cin>>input;
            arr[input-1][0]++;
        }
        cin>>b;
        for (int j=0; j<b; j++)
        {
            int input;
            cin>>input;
            arr[input-1][1]++;
        }

        for (int j=3; j>=0; j--)
        {
            if (arr[j][0]>arr[j][1])
            {
                cout<<"A\n";
                break;
            }
            else if (arr[j][1]>arr[j][0])
            {
                cout<<"B\n";
                break;
            }
            else if (j==0)
                cout<<"D\n";
        }
    }

    return 0;
}
