//https://chasingstar.tistory.com/22
#include <iostream>
#include <cstring>
#include <cmath>

#define TEN_EIGHTEEN 1000000000000000000  //10^18

using namespace std;

struct Data {
    long long first_block_number;
    int size;  //(수의 길이/18)을 올림한 값 == 사용한 칸 수
} fibo[100010];

//피보나치 값을 구합니다.
void GetFibo() {
    long long f[3][1200];  //피보나치 값을 구하기 위한 배열
    int now, before1, before2;

    f[1][0] = 1;
    fibo[1].first_block_number = 1;
    fibo[1].size = 1;
    for (int i=2; i<=100000; i++) {
        now = i%3;
        before1 = (i-1)%3;
        before2 = (i-2)%3;

        long long add = 0;
        for (int j=0; j<(double)fibo[i-1].size; j++) {
            add += f[before1][j]+f[before2][j];
            if (add>=TEN_EIGHTEEN) {  //받아올림 처리
                f[now][j] = add-TEN_EIGHTEEN;
                add = 1;
            }
            else {
                f[now][j] = add;
                add = 0;
            }
        }
        now[f][fibo[i-1].size] = add;
        fibo[i].size = (add!=0 ? fibo[i-1].size+1 : fibo[i-1].size);  //size 등록
        fibo[i].first_block_number = f[now][fibo[i].size-1];  //첫번째 블록의 수 등록
    }

    return;
}

//이분 탐색으로 해당 값을 구합니다.
int Search(long long first_block_number, int size) {
    int first = 0, last = 100000;
    while (first<=last) {
        int mid = (first+last)/2;
        if (fibo[mid].first_block_number==first_block_number && fibo[mid].size==size)
            return mid;
        else if (size<fibo[mid].size || (size==fibo[mid].size && first_block_number<fibo[mid].first_block_number))
            last = mid-1;
        else
            first = mid+1;
    }
    return -1;
}

int main() {
    int t;
    char fn[21010] = {0};

    GetFibo();
    cin>>t;
    for (int i=0; i<t; i++) {
        cin>>fn;
        int len = strlen(fn);
        long long num = 0;
        for (int i=0; i<(len-1)%18+1; i++)
            num = num*10+(fn[i]-'0');
        if (num==1 && len==1)
            cout<<'2'<<'\n';
        else
            cout<<Search(num, ceil((double)len/18))<<'\n';
    }

    return 0;
}
