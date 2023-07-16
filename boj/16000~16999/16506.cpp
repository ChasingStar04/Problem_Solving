//엄청 귀찮은 구현 문제
#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

map<string, string> opcode;

void SetOpcode()
{
    opcode.insert({"ADD", "0000"});
    opcode.insert({"SUB", "0001"});
    opcode.insert({"MOV", "0010"});
    opcode.insert({"AND", "0011"});
    opcode.insert({"OR", "0100"});
    opcode.insert({"NOT", "0101"});
    opcode.insert({"MULT", "0110"});
    opcode.insert({"LSFTL", "0111"});
    opcode.insert({"LSFTR", "1000"});
    opcode.insert({"ASFTR", "1001"});
    opcode.insert({"RL", "1010"});
    opcode.insert({"RR", "1011"});
    return;
}

void PrintBit(int len, int num)
{
    for (int i=len-1; i>=0; i--)
    {
        cout<<num/(int)pow(2, i);
        num %= (int)pow(2, i);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    
    SetOpcode();

    cin>>n;
    for (int i=0; i<n; i++)
    {
        string opc;
        int d, a, b;

        cin>>opc>>d>>a>>b;
        if (opc.back()=='C')
        {
            opc.pop_back();
            cout<<opcode[opc];
            cout<<"10";
            PrintBit(3, d);
            if (opc=="MOV" or opc=="NOT")
                cout<<"000";
            else
                PrintBit(3, a);
            PrintBit(4, b);
        }
        else
        {
            cout<<opcode[opc];
            cout<<"00";
            PrintBit(3, d);
            if (opc=="MOV" or opc=="NOT")
                cout<<"000";
            else
                PrintBit(3, a);
            PrintBit(3, b);
            cout<<'0';
        }
        cout<<'\n';
    }

    return 0;
}
