/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-02-03 21:11:18                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 70                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11354
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e5,inf=1e9;

int a[N+2],b[N+2],c[N+2],ans[N+2],l[N+2],r[N+2],par[N+2];
vector<int>rt[N+2],qq[N+2];
int get(int x)
{
  while(x!=par[x])x=par[x];
  return x;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,f=0;
  while(cin>>n>>m)
  {
    if(f)cout<<'\n';f=1;
    if(n==-1&&m==-1)break;

    vector<vector<int> >v(m);
    for(int i=0;i<m;i++)
    {
      v[i].resize(3);
      cin>>v[i][1]>>v[i][2]>>v[i][0];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++)
      a[i+1]=v[i][0],b[i+1]=v[i][1],c[i+1]=v[i][2];

    int q;cin>>q;
    for(int i=1;i<=n;i++)qq[i].clear();
    for(int i=1;i<=q;i++)
    {
      cin>>l[i]>>r[i];qq[l[i]].push_back(i);qq[r[i]].push_back(i);
      ans[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
      par[i]=i;rt[i].clear();
      rt[i].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
      int r1=get(b[i]),r2=get(c[i]);
      if(r1==r2)continue;

      if((int)rt[r1].size()>(int)rt[r2].size())swap(r1,r2);

      par[r1]=r2;
      for(auto x:rt[r1])
      {
        for(auto id:qq[x])
        {
          if(ans[id]!=-1)continue;
          if(get(l[id])==get(r[id]))ans[id]=a[i];
        }
      }
      for(auto x:rt[r1])rt[r2].push_back(x);
      rt[r1].clear();
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
  }
  return 0;
}