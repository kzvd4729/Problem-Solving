/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2021 22:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1200 ms                                         memory_used: 33900 KB                             
*  problem: https://codeforces.com/contest/1487/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5,inf=1e9,mod=1e9+7;
 int n[4+2],a[4+2][N+2];long cost[N+2],ncost[N+2];
vector<int>ad[4+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=4;i++)cin>>n[i];
   for(int i=1;i<=4;i++)
  {
    for(int j=1;j<=n[i];j++)cin>>a[i][j];
  }
   for(int i=2;i<=4;i++)
  {
    int m;cin>>m;
    for(int j=1;j<=m;j++)
    {
      int u,v;cin>>u>>v;
      ad[i][v].push_back(u);
    }
  }
  for(int i=1;i<=n[1];i++)cost[i]=a[1][i];
  for(int i=2;i<=4;i++)
  {
    multiset<long>st;
    for(int j=1;j<=n[i-1];j++)st.insert(cost[j]);
    st.insert(1LL*inf*inf);
     for(int j=1;j<=n[i];j++)
    {
      for(auto x:ad[i][j])
        st.erase(st.find(cost[x]));
       ncost[j]=*st.begin()+a[i][j];
      ncost[j]=min(ncost[j],1LL*inf*inf);
            for(auto x:ad[i][j])
        st.insert(cost[x]);
    }
    for(int j=1;j<=n[i];j++)cost[j]=ncost[j];
  }
  long mn=1LL*inf*inf;
  for(int i=1;i<=n[4];i++)mn=min(mn,cost[i]);
   if(mn==1LL*inf*inf)mn=-1;
  cout<<mn<<endl;
   return 0;
}