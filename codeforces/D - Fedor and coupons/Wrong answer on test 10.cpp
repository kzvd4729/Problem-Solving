/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/23/2018 15:59                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 11900 KB                             
*  problem: https://codeforces.com/contest/754/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
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
  sort(pp+1,pp+n+n+1);set<pair<int,int> >st;
   int ans=0,last=inf;
  for(int i=1;i<=n+n;i++)
  {
    if(pp[i].second<0)
    {
      st.insert({pp[i]});
      if(st.size()==k)
        last=st.rbegin()->first;
    }
    else
    {
      ans=max(ans,pp[i].first-last+1);
      st.erase({mm[pp[i].second].first,-pp[i].second});
      if(st.size()<k)last=inf;
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
   st.clear();
  int ans2=0;last=inf;
  for(int i=1;i<=n+n;i++)
  {
    if(pp[i].second<0)
    {
      st.insert({pp[i]});
      if(st.size()==k)
        last=st.rbegin()->first;
    }
    else
    {
      ans2=max(ans2,pp[i].first-last+1);
      if(ans2==ans)
      {
        while(k--)
        {
          cout<<-st.begin()->second<<" ";
          st.erase(*st.begin());
        }
        exit(0);
      }
      st.erase({mm[pp[i].second].first,-pp[i].second});
      if(st.size()<k)last=inf;
    }
  }
   return 0;
}