#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct xyc
{
    int x; //x계수
    int y; //y계수
    int c; //c계수
};

vector<string> StringSplit(string str)
{
    vector<string> v;
    
    string s;
    for (char &c : str)
    {
        if (c==' ')
        {
            if (s.length()>0) v.push_back(s);
            s.clear();
        }
        else
            s.push_back(c);
    }
    if (s.length()>0) v.push_back(s);

    return v;
}

xyc GetXYC(vector<string> v)
{
    xyc ans = {0};
    int me = 1; //meet equal(=)
    int pm = 1; //+-

    for (string s : v)
    {
        if (s.find('=')!=string::npos)
        {
            me = -1;
            pm = 1;
        }
        else if (s.length()==1 && s.find('+')!=string::npos)
            pm = 1;
        else if (s.length()==1 && s.find('-')!=string::npos)
            pm = -1;
        else
        {
            if (s.find('x')!=string::npos)
            {
                s.pop_back();
                if (s.length()==0)
                    ans.x += me*pm;
                else if (s=="-")
                    ans.x += me*pm*-1;
                else
                    ans.x += me*pm*stoi(s);
            }
            else if (s.find('y')!=string::npos)
            {
                s.pop_back();
                if (s.length()==0)
                    ans.y += me*pm;
                else if (s=="-")
                    ans.y += me*pm*-1;
                else
                    ans.y += me*pm*stoi(s);
            }
            else
                ans.c += me*pm*stoi(s);
        }
    }
    
    return ans;
}

int QGD(int a, int b)
{
    if (b==0)
        return a;
    else
        return QGD(b, a%b);
}

void PrintBunSu(int a, int b)
{
    if (b<0)
    {
        a *= -1;
        b *= -1;
    }
    if (b==1)
        cout<<a<<'\n';
    else
        cout<<a<<'/'<<b<<'\n';
}

int main()
{
    int t;

    cin>>t;
    cin.ignore();
    for (int i=0; i<t; i++)
    {
        if (i>0)
        {
            string ns;
            getline(cin, ns);
        }
        string str1, str2;
        vector<string> v1, v2;
        xyc c1, c2;

        getline(cin, str1);
        v1 = StringSplit(str1);
        c1 = GetXYC(v1);
        //cout<<c1.x<<' '<<c1.y<<' '<<c1.c<<'\n';

        getline(cin, str2);
        v2 = StringSplit(str2);
        c2 = GetXYC(v2);
        //cout<<c2.x<<' '<<c2.y<<' '<<c2.c<<'\n';

        if (c1.x!=0 && c1.y!=0 && c1.c!=0) //식1 초벌약분
        {
            int q = QGD(QGD(abs(c1.x), abs(c1.y)), abs(c1.c));
            c1.x /= q;
            c1.y /= q;
            c1.c /= q;
        }
        else if (c1.x==0 && c1.y!=0 && c1.c!=0)
        {
            int q = QGD(abs(c1.y), abs(c1.c));
            c1.y /= q;
            c1.c /= q;
        }
        else if (c1.x!=0 && c1.y==0 && c1.c!=0)
        {
            int q = QGD(abs(c1.x), abs(c1.c));
            c1.x /= q;
            c1.c /= q;
        }
        else if (c1.x!=0 && c1.y!=0 && c1.c==0)
        {
            int q = QGD(abs(c1.x), abs(c1.y));
            c1.x /= q;
            c1.y /= q;
        }

        if (c2.x!=0 && c2.y!=0 && c2.c!=0) //식2 초벌약분
        {
            int q = QGD(QGD(abs(c2.x), abs(c2.y)), abs(c2.c));
            c2.x /= q;
            c2.y /= q;
            c2.c /= q;
        }
        else if (c2.x==0 && c2.y!=0 && c2.c!=0)
        {
            int q = QGD(abs(c2.y), abs(c2.c));
            c2.y /= q;
            c2.c /= q;
        }
        else if (c2.x!=0 && c2.y==0 && c2.c!=0)
        {
            int q = QGD(abs(c2.x), abs(c2.c));
            c2.x /= q;
            c2.c /= q;
        }
        else if (c2.x!=0 && c2.y!=0 && c2.c==0)
        {
            int q = QGD(abs(c2.x), abs(c2.y));
            c2.x /= q;
            c2.y /= q;
        }

        if (c1.x*c2.y!=c1.y*c2.x) //해가존재
        {
            int xs = c2.y*c1.c - c1.y*c2.c;
            int xm = c1.y*c2.x - c2.y*c1.x;
            int xq = QGD(abs(xs), abs(xm));
            
            xs /= xq;
            xm /= xq;
            PrintBunSu(xs, xm);
            
            int ys = c2.x*c1.c - c1.x*c2.c;
            int ym = c1.x*c2.y - c2.x*c1.y;
            int yq = QGD(abs(ys), abs(ym));
            
            ys /= yq;
            ym /= yq;
            PrintBunSu(ys, ym);
        }
        else
        {
            if ((c1.x==0 && c1.y==0 && c1.c!=0) || (c2.x==0 && c2.y==0 && c2.c!=0))
            {
                cout<<"don't know\n";
                cout<<"don't know\n";
            }
            else if (c1.x==0 && c1.y==0 && c2.x==0 && c2.y==0)
            {
                cout<<"don't know\n";
                cout<<"don't know\n";
            }
            else if (c1.x==0 && c1.y!=0 && c2.x==0 && c2.y!=0)
            {
                cout<<"don't know\n";
                if (c1.c==c2.c)
                    PrintBunSu(c1.c*-1, c1.y);
                else
                    cout<<"don't know\n";
            }
            else if (c1.x!=0 && c1.y==0 && c2.x!=0 && c2.y==0)
            {
                if (c1.c==c2.c)
                    PrintBunSu(c1.c*-1, c1.x);
                else
                    cout<<"don't know\n";
                cout<<"don't know\n";
            }
            else if (c1.x!=0 && c1.y==0 && c2.x==0 && c2.y==0)
            {
                PrintBunSu(c1.c*-1, c1.x);
                cout<<"don't know\n";
            }
            else if (c1.x==0 && c1.y!=0 && c2.x==0 && c2.y==0)
            {
                cout<<"don't know\n";
                PrintBunSu(c1.c*-1, c1.y);
            }
            else if (c1.x==0 && c1.y==0 && c2.x!=0 && c2.y==0)
            {
                PrintBunSu(c2.c*-1, c2.x);
                cout<<"don't know\n";
            }
            else if (c1.x==0 && c1.y==0 && c2.x==0 && c2.y!=0)
            {
                cout<<"don't know\n";
                PrintBunSu(c2.c*-1, c2.y);
            }
            else
            {
                cout<<"don't know\n";
                cout<<"don't know\n";
            }
        }
        cout<<'\n';
    }

    return 0;
}
