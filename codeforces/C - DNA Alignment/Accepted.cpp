/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/28/2017 21:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/520/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define m 1000000007
using namespace std;
long fre[9999],mx,cnt,n;
string s;
long bigmod(long b,long p)
{
    if(p==0)return 1;
    if(p%2==0)return bigmod((b*b)%m,p/2)%m;
    else return (b*bigmod((b*b)%m,p/2))%m;
}
int main()
{
    cin>>n;
    cin>>s;
    for(long i=0;i<s.size();i++)
    {
        fre[s[i]]++;
    }
     for(long i=0;i<9999;i++)
    {
        mx=max(mx,fre[i]);
    }
     for(long i=0;i<9999;i++)
    {
        if(fre[i]==mx)cnt++;
    }
     cout<<bigmod(cnt,n)<<endl;
     return 0;
}
 