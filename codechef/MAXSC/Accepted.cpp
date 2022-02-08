/****************************************************************************************
*  @author: kzvd4729                                         created: 05-01-2018 15:36:07                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.43 sec                                        memory_used: 19.5M                                
*  problem: https://www.codechef.com/JAN18/problems/MAXSC
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,mat[707][707];
int main()
{
cin>>t;
while(t--)
{
cin>>n;
for(long i=1;i<=n;i++)
{
for(long j=1;j<=n;j++)
{
cin>>mat[i][j];        
}
}
long picked=99999999999999,ans=0,f=0;
for(long i=n;i>=1;i--)
{
long mx=0;
for(long j=1;j<=n;j++)
{
if(mat[i][j]<picked)mx=max(mx,mat[i][j]);
}
if(mx==0)f=1;
picked=mx;
ans+=picked;
}
if(f==1)cout<<-1<<endl;
else cout<<ans<<endl;
}
return 0;
}