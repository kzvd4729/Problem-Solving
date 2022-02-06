/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/04/2017 23:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/489/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long m,s,gr[101],sm[101];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>m>>s;
    if(s==0)
    {
        if(m==1)cout<<0<<" "<<0<<endl;
        else cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    if(s>m*9)
    {
        cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    long ss=s;
    ss--;
    for(long i=m; i>=1; i--)
    {
        if(ss>9)
        {
            sm[i]=9;
            ss-=9;
        }
        else
        {
            sm[i]=ss;
            ss=0;
        }
    }
    sm[1]++;
    for(long i=1;i<=m;i++)
    {
        if(s>9)
        {
            gr[i]=9;
            s-=9;
        }
        else
        {
            gr[i]=s;
            s=0;
        }
    }
    for(long i=1;i<=m;i++)cout<<sm[i];
    cout<<" ";
    for(long i=1;i<=m;i++)cout<<gr[i];
     return 0;
}
 