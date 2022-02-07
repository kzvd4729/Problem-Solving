/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-02-03 20:50:45                      
*  solution_verdict: Time Limit Exceed                       language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11354
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9;

int a[N+2],b[N+2],c[N+2],ans[N+2],l[N+2],r[N+2],par[N+2];
int get(int x)
{
  while(x!=par[x])
  {
    par[x]=par[par[x]];
    x=par[x];
  }
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
    for(int i=1;i<=q;i++)
    {
      cin>>l[i]>>r[i];
      ans[i]=-1;
    }
    for(int i=1;i<=n;i++)par[i]=i;
    for(int i=1;i<=m;i++)
    {
      int r1=get(b[i]),r2=get(c[i]);
      if(r1==r2)continue;

      par[r1]=r2;
      for(int j=1;j<=q;j++)
      {
        if(ans[j]!=-1)continue;
        if(get(l[j])==get(r[j]))ans[j]=a[i];
      }
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
  }
  return 0;
}