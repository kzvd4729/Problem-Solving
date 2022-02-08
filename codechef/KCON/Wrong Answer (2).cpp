/****************************************************************************************
*  @author: kzvd4729                                         created: 05-01-2018 16:33:45                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.6M                                
*  problem: https://www.codechef.com/JAN18/problems/KCON
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,k,arr[100005],lft,rgt,mx,ans,sum,all;
int main()
{
cin>>t;
while(t--)
{
cin>>n>>k;
all=0;
for(long i=1;i<=n;i++)cin>>arr[i],all+=arr[i];
mx=0,sum=0;
for(long i=1;i<=n;i++)
{
sum+=arr[i];
if(sum<0)sum=0;
mx=max(mx,sum);
}
ans=mx;
if(k==1)
{
cout<<ans<<endl;
continue;
}
lft=0,sum=0;
for(long i=1;i<=n;i++)
{
sum+=arr[i];
lft=max(lft,sum);
}
rgt=0,sum=0;
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