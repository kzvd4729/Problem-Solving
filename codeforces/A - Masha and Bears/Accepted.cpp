/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/24/2017 14:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/907/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c,d,i,j,k,f;
bool check(long x,long y,long z)
{
    if(x>=y||x>=z||y>=z)return false;
    if(x>=d&&2*d>=x&&2*d<y)return true;
return false;
}
int main()
{
cin>>a>>b>>c>>d;
for(i=c;i<=2*c;i++)
{
for(j=b;j<=2*b;j++)
{
for(k=a;k<=2*a;k++)
{
if(check(i,j,k))
{
    f=1;
break;
}
}
if(f==1)break;
}
if(f==1)break;
}
if(f==1)
{
cout<<k<<endl<<j<<endl<<i<<endl;
}
else cout<<-1<<endl;
 return 0;
}