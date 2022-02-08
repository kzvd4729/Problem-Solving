/****************************************************************************************
*  @author: kzvd4729                                         created: 30-11-2019 19:43:17                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.12 sec                                        memory_used: 19.5M                                
*  problem: https://www.codechef.com/LTIME78A/problems/DEADEND
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    sort(aa+1,aa+n+1);
    int ans=0,ls=-2;aa[n+1]=1e9+9;
    for(int i=1;i<=n;i++)
    {
      if(abs(aa[i]-ls)==1||abs(aa[i]-aa[i+1])==1)
      {
        ls=aa[i];
      }
      else ans++,ls=aa[i]+1;
    }
    cout<<ans<<"\n";
  }
  return 0;
}