/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/29/2017 10:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/911/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c,vis[100002],arr[5];
int main()
{
cin>>arr[1]>>arr[2]>>arr[3];
sort(arr+1,arr+4);
for(long i=1;i<=100000;i+=arr[1])vis[i]=1;
for(long i=1;i<=100000;i++)
{
if(vis[i]==0)
{
for(long j=i;j<=100000;j+=arr[2])vis[j]=1;
break;
}
}
for(long i=1;i<=100000;i++)
{
if(vis[i]==0)
{
for(long j=i;j<=100000;j+=arr[3])vis[j]=1;
break;
}
}
for(long i=1;i<=100000;i++)
{
if(vis[i]==0)
{
cout<<"NO"<<endl;
return 0;
}
}
cout<<"YES"<<endl;
return 0;
}