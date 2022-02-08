/****************************************************************************************
*  @author: kzvd4729                                         created: 05-01-2018 17:08:17                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.13 sec                                        memory_used: 15.6M                                
*  problem: https://www.codechef.com/JAN18/problems/KCON
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,k,arr[100005],all,lft,rgt,ans,mx,sum;
const long inf =-9999999999999999;
int main()
{
cin>>t;
while(t--)
{
cin>>n>>k;
all=0;
for(long i=1;i<=n;i++)cin>>arr[i],all+=arr[i];
sum=0,mx=inf;
for(long i=1;i<=n;i++)
{
sum+=arr[i];
mx=max(mx,sum);
if(sum<0)sum=0;
}
ans=mx;
if(k==1)
{
cout<<ans<<endl;
continue;
}
sum=0,lft=inf;
for(long i=1;i<=n;i++)
{
sum+=arr[i];
lft=max(lft,sum);
}
sum=0,rgt=inf;
for(long i=n;i>=1;i--)
{
sum+=arr[i];
rgt=max(rgt,sum);
}
ans=max(ans,rgt+lft);
ans=max(ans,rgt+lft+all*(k-2));
cout<<ans<<endl;
}
return 0;
}