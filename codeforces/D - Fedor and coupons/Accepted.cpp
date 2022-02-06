/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/23/2018 16:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 592 ms                                          memory_used: 19200 KB                             
*  problem: https://codeforces.com/contest/754/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define long long long
using namespace std;
using namespace __gnu_pbds;
 typedef
tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
 const int N=3e5,inf=2e9;
pair<int,int>pp[N+N+2],mm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>pp[i].first;pp[i].second=-i;
    cin>>pp[n+i].first;pp[n+i].second=i;
    mm[i]={pp[i].first,pp[n+i].first};
  }
  sort(pp+1,pp+n+n+1);ordered_set st;
   int ans=0;
  for(int i=1;i<=n+n;i++)
  {
    if(pp[i].second<0)st.insert(pp[i]);
    else
    {
      if(st.size()>=k)
      {
        auto it=st.find_by_order(k-1);
        ans=max(ans,pp[i].first-it->first+1);
      }
      st.erase({mm[pp[i].second].first,-pp[i].second});
    }
  }
  cout<<ans<<endl;
  if(ans==0)
  {
    for(int i=1;i<=k;i++)
      cout<<i<<" ";
    cout<<endl;
    exit(0);
  }
   st.clear();int ans2=0;
  for(int i=1;i<=n+n;i++)
  {
    if(pp[i].second<0)st.insert(pp[i]);
    else
    {
      if(st.size()>=k)
      {
        auto it=st.find_by_order(k-1);
        ans2=max(ans2,pp[i].first-it->first+1);
      }
      if(ans2==ans)
      {
        while(k--)
        {
          cout<<-st.begin()->second<<" ";
          st.erase(*st.begin());
        }
        return 0;
      }
      st.erase({mm[pp[i].second].first,-pp[i].second});
    }
  }
   return 0;
}