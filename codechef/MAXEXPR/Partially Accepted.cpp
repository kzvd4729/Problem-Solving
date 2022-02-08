/****************************************************************************************
*  @author: kzvd4729                                         created: 03-08-2019 16:16:24                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.23 sec                                        memory_used: 30.1M                                
*  problem: https://www.codechef.com/AUG19A/problems/MAXEXPR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double eps=1e-10;
double aa[N+2],ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;double add=0;
    for(int i=1;i<=n;i++)cin>>aa[i],add+=aa[i];
    for(int i=1;i<=n;i++)cin>>ans[i],ans[i]*=-1.0;
    double tot=0;
    for(int i=1;i<=n;i++)
      tot+=ans[i]*aa[i];
    if(tot>eps){cout<<-1<<endl;continue;}
    double lo=0,hi=1e9,md;
    while(hi-lo>eps)
    {
      md=(lo+hi)/2.0;tot=0;
      for(int i=1;i<=n;i++)
        tot+=(ans[i]+md)*aa[i];
      if(tot<eps)lo=md;else hi=md;
    }
    double sum=0;
    for(int i=1;i<=n;i++)
      sum+=sqrt(md);
    cout<<setprecision(2)<<fixed;
    cout<<sum<<endl;
    for(int i=1;i<=n;i++)
      cout<<ans[i]+md<<" ";
    cout<<endl;
  }
  return 0;
}