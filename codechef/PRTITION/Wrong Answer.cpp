/****************************************************************************************
*  @author: kzvd4729                                         created: 06-01-2018 09:45:28                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 35.8M                                
*  problem: https://www.codechef.com/JAN18/problems/PRTITION
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,x,n,vis[1000006],sum,sm,f;
void dfs(long z)
{
for(long i=z;i>=1;i--)
{
if(i==x)continue;
if(sm+i==sum)
{
f=1;
vis[i]=1;
return ;        
}
if(sm+i<sum)
{
sm+=i;
vis[i]=1;
dfs(i-1);
if(f==1)return ;
sm-=i;
vis[i]=0;  
}
}
}
int main()
{
cin>>t;
while(t--)
{
cin>>x>>n;
for(long i=1;i<=n;i++)vis[i]=0;
vis[x]=2; 
sum=(n*(n+1))/2;
sum-=x;
if(sum%2==1)
{
cout<<"impossible"<<endl;
continue;
}
sum/=2;
f=0;
sm=0;
dfs(n);
for(long i=1;i<=n;i++)cout<<vis[i];
cout<<endl;
}
return 0;
}