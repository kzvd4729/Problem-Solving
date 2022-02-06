/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2019 19:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1638 ms                                         memory_used: 82500 KB                             
*  problem: https://codeforces.com/gym/100814/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int par[N+2],sz[N+2],ans[N+2];
vector<int>root[N+2];
vector<pair<int,int> >nd[N+2];
map<int,int>mp[N+2];
int get(int x)
{
  if(par[x]==x)return x;return get(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;vector<vector<int> >s(m+1);
    for(int i=1;i<=max(n,m);i++)
    {
      nd[i].clear(),root[i].clear(),ans[i]=0,mp[i].clear();
    }
    for(int i=1;i<=m;i++)
    {
      s[i].resize(3);assert((s[i][1]==s[i][2]));
       cin>>s[i][0]>>s[i][1]>>s[i][2];
      if(s[i][0]==2)
        nd[s[i][1]].push_back({s[i][2],i}),nd[s[i][2]].push_back({s[i][1],i});
    }
    for(int i=1;i<=n;i++)
    {
      par[i]=i,sz[i]=1,mp[i][i]=1;
      root[i].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
      if(s[i][0]==2)continue;
      int r1=get(s[i][1]),r2=get(s[i][2]);
      if(r1==r2)continue;
       if(sz[r1]>sz[r2])swap(r1,r2);
       for(auto x:root[r1])
      {
        for(auto z:nd[x])
        {
          if(ans[z.second])continue;
          if(mp[r2][z.first])ans[z.second]=i;
        }
      }
      par[r1]=r2,sz[r2]+=sz[r1];
      for(auto x:root[r1])root[r2].push_back(x),mp[r2][x]=1;
    }
     for(int i=1;i<=m;i++)
    {
      if(s[i][0]==1)continue;
      if(ans[i]==0||ans[i]>i)ans[i]=-1;
      cout<<ans[i]<<"\n";
    }
  }
  return 0;
}