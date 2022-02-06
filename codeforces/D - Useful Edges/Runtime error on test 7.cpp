/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2021 01:02                        
*  solution_verdict: Runtime error on test 7                 language: GNU C++17 (64)                          
*  run_time: 452 ms                                          memory_used: 10700 KB                             
*  problem: https://codeforces.com/contest/1483/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=600,inf=1e9,mod=1e9+7;
const long INF=1LL*inf*inf;
 long a[N+2][N+2],uu[N+2],vv[N+2],ll[N+2],mx[N+2];
vector<pair<int,int> >ad[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=INF;
  for(int i=1;i<=n;i++)a[i][i]=0;
   for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ad[u].push_back({v,w});ad[v].push_back({u,w});
    a[u][v]=min(a[u][v],1LL*w);a[v][u]=min(a[v][u],1LL*w);
  }
   for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    }
  }
   int q;cin>>q;
  for(int i=1;i<=q;i++)cin>>uu[i]>>vv[i]>>ll[i];
   int ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int i=1;i<=n;i++)mx[i]=-INF;
    for(int j=1;j<=q;j++)
    {
      mx[vv[j]]=max(mx[vv[j]],ll[j]-a[i][uu[j]]);
      mx[uu[j]]=max(mx[uu[j]],ll[j]-a[i][vv[j]]);
    }
    //for(int j=1;j<=n;j++)cout<<mx[j]<<" ";cout<<endl;
    for(auto x:ad[i])
    {
      int cs=x.second,nd=x.first,f=0;
      for(int j=1;j<=n;j++)
      {
        if(a[nd][j]+cs<=mx[j])f=1;
      }
      ans+=f;
    }
  }
  cout<<ans/2<<endl;
    return 0;
}