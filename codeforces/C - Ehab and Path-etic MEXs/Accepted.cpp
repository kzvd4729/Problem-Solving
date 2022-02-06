/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/14/2020 21:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 15100 KB                             
*  problem: https://codeforces.com/contest/1325/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int dg[N+2],id[N+2],ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n-1;i++)
  {
    int u,v;cin>>u>>v;dg[u]++,dg[v]++;
    id[u]=i,id[v]=i;
  }
  int cnt=0;
  for(int i=1;i<=n;i++)
    if(dg[i]==1)cnt++;
   set<int>st;memset(ans,-1,sizeof(ans));
  for(int i=0;i<n-1;i++)st.insert(i);
   if(cnt>=3)
  {
    cnt=3;
    for(int i=1;i<=n;i++)
    {
      if(dg[i]==1)
      {
        //cout<<"*"<<i<<endl;
        ans[id[i]]=*st.begin();st.erase(*st.begin());
        cnt--;if(cnt==0)break;
      }
    }
  }
  for(int i=0;i<n-1;i++)
  {
    if(ans[i]==-1)
    {
      cout<<*st.begin()<<"\n";
      st.erase(*st.begin());
    }
    else cout<<ans[i]<<"\n";
  }
  return 0;
}