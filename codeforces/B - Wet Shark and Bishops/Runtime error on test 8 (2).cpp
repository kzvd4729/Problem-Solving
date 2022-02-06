/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/08/2018 09:36                        
*  solution_verdict: Runtime error on test 8                 language: GNU C++14                               
*  run_time: 390 ms                                          memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/621/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long vis[1004][1004],n,x,y,cnt;
int main()
{
cin>>n;
for(long i=1;i<=n;i++)
{
cin>>x>>y;
vis[x][y]=1;
}
long ans=0;
for(long i=1;i<=n;i++)
{
cnt=0;
for(long j=1,k=i;j<=i,k>=1;j++,k--)
{
if(vis[j][k])cnt++;
}
ans+=(cnt*(cnt-1))/2;
}
for(long i=n;i>=2;i--)
{
cnt=0;
for(long j=i,k=n;j<=n,k>=i;j++,k--)
{
if(vis[j][k])cnt++;
}
ans+=(cnt*(cnt-1))/2;
}
for(long i=1;i<=n;i++)
{
cnt=0;
for(long j=1,k=n-i+1;j<=i,k<=n;j++,k++)
{
if(vis[j][k])cnt++;     
}
ans+=(cnt*(cnt-1))/2;
}
for(long i=1;i<=n-1;i++)
{
cnt=0;
for(long j=1,k=n-i+1;j<=i,k<=n;j++,k++)
{
if(vis[k][j])cnt++;     
}
ans+=(cnt*(cnt-1))/2;
}
cout<<ans<<endl;
return 0;
}