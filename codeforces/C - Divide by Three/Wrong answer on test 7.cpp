/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/06/2017 19:33                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2300 KB                              
*  problem: https://codeforces.com/contest/792/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int l,qm,mark;
int mod[100005];
void Remainder(void)
{
    int i;
    qm=0;
    mark=0;
    for(i=0;i<l;i++)
    {
        mod[i]=(s[i]-'0')%3;
        if(mod[i]==0)mark=1;
        qm=qm+mod[i];
    }
}
void print(int n)
{
    int i,f=0;
    for(i=0;i<l;i++)
    {
        if(i!=n&&(f==1||s[i]!='0'))
        {
            cout<<s[i];
            f=1;
        }
    }
    if(f==0)
    {
        if(mark==1)cout<<0;
        else cout<<-1;
    }
    cout<<endl;
    return ;
}
int main()
{
    int i,x,ff;
    while(cin>>s)
    {
        l=s.size();
        Remainder();
        if(qm%3==0)cout<<s<<endl;
        else
        {
            ff=0;
            for(i=0;i<l;i++)
            {
                x=qm-mod[i];
                if(x%3==0)
                {
                    ff=1;
                    print(i);
                }
            }
            if(ff==0)cout<<-1<<endl;
        }
    }
    return 0;
}