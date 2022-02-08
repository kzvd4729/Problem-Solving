/****************************************************************************************
*  @author: kzvd4729                                         created: 05-01-2018 16:49:46                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.12 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/JAN18/problems/KCON
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,k,x;
vector<long>v;
int main()
{
cin>>t;
while(t--)
{
v.clear();
cin>>n>>k;
for(long i=1;i<=n;i++)
{
cin>>x;
v.push_back(x);       
}
for(long i=1;i<k;i++)
{
for(long j=0;j<n;j++)v.push_back(v[j]);
}
long sum=0,ans=-9999999999999999;
for(long i=0;i<v.size();i++)
{
sum+=v[i];
ans=max(ans,sum);
if(sum<0)sum=0;
}
cout<<ans<<endl;
}
return 0;
}