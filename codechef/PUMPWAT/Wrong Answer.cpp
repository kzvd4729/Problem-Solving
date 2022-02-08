/****************************************************************************************
*  @author: kzvd4729                                         created: 21-10-2018 21:47:53                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.16 sec                                        memory_used: 20.8M                                
*  problem: https://www.codechef.com/COOK99A/problems/PUMPWAT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=2e9;
int aa[N+2],dp[N+2],pd[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    memset(dp,0,sizeof(dp));
    memset(pd,0,sizeof(pd));
    set<pair<int,int> >st;
    st.insert({inf,inf});
    for(int i=n;i>=1;i--)
    {
      auto p=st.upper_bound(make_pair(aa[i],inf));
      if(p->first==inf)dp[i]=1;
      else dp[i]=dp[p->second]+1;
      st.insert({aa[i],i});
    }
    st.clear();
    st.insert({inf,inf});
    for(int i=1;i<=n;i++)
    {
      auto p=st.upper_bound(make_pair(aa[i],inf));
      if(p->first==inf)pd[i]=1;
      else pd[i]=pd[p->second]+1;
      st.insert({aa[i],i});
    }
//    for(int i=0;i<=n+1;i++)
//      cout<<dp[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<=n+1;i++)
//      cout<<pd[i]<<" ";
//    cout<<endl;
    int ans=inf;
    for(int i=0;i<=n;i++)
    {
      ans=min(ans,pd[i]+dp[i+1]);
    }
    cout<<ans<<endl;
  }
  return 0;
}