/****************************************************************************************
*  @author: kzvd4729                                         created: 05-01-2018 16:42:50                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
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
long sum=0,ans=0;
for(long i=0;i<v.size();i++)
{
sum+=v[i];
if(sum<0)sum=0;
ans=max(ans,sum);
}
cout<<ans<<endl;
}
return 0;
}