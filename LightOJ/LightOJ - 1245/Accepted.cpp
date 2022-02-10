/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-23 15:07:16                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 763                                        memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1245
****************************************************************************************/
#include<bits/stdc++.h>
#define long unsigned long long
using namespace std;
long t,tc,n;
 
int main()
{
cin>>t;
while(t--)
{
cin>>n;
long lim=sqrt(n),ans=0,pre=n;
for(long i=2;i<=lim;i++)
{
long tmp=n/i;
ans=ans+(pre-tmp)*(i-1);
pre=tmp;
}
//cout<<ans<<endl;
for(long i=1;i<=pre;i++)ans+=n/i;
cout<<"Case "<<++tc<<": "<<ans<<endl;
}
return 0;
}