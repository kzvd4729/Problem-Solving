/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2018 12:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1308 ms                                         memory_used: 10300 KB                             
*  problem: https://codeforces.com/contest/348/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long arr[N+2],vis[N+2],bty[N+2];
long ban[N+2],san[N+2],sty[N+2];
vector<long>big[N+2],sml[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,q,bg=0,sm=0;cin>>n>>m>>q;
  for(long i=1;i<=n;i++)cin>>arr[i];
  for(long i=1;i<=m;i++)
  {
    long k;cin>>k;
    if(k>2000)
    {
      ++bg;bty[i]=bg;
      while(k--)
      {
        long x;cin>>x;ban[bg]+=arr[x];
        big[bg].push_back(x);
      }
    }
    else
    {
      ++sm;sty[i]=sm;
      while(k--)
      {
        long x;cin>>x;san[sm]+=arr[x];
        sml[sm].push_back(x);
      }
    }
  }
  long crs[bg+2][sm+2];memset(crs,0,sizeof(crs));
  for(long i=1;i<=bg;i++)
  {
    for(auto x:big[i])vis[x]=1;
    for(long j=1;j<=sm;j++)
    {
      for(auto x:sml[j])
      {
        if(vis[x])crs[i][j]++;
      }
    }
    for(auto x:big[i])vis[x]=0;
  }
  long bbc[bg+2][bg+2];memset(bbc,0,sizeof(bbc));
  for(long i=1;i<=bg;i++)
  {
    for(auto x:big[i])vis[x]=1;
    for(long j=1;j<=bg;j++)
    {
      for(auto x:big[j])
      {
        if(vis[x])bbc[i][j]++;
      }
    }
    for(auto x:big[i])vis[x]=0;
  }
  memset(arr,0,sizeof(arr));
  while(q--)
  {
    char c;cin>>c;
    if(c=='?')
    {
      long id;cin>>id;
      if(sty[id])
      {
        id=sty[id];long ans=san[id];
        for(auto x:sml[id])
          ans+=arr[x];
        cout<<ans<<endl;
      }
      else cout<<ban[bty[id]]<<endl;
    }
    else
    {
      long id,z;cin>>id>>z;
      if(sty[id])
      {
        id=sty[id];
        for(auto x:sml[id])arr[x]+=z;
        for(long i=1;i<=bg;i++)
          ban[i]+=z*crs[i][id];
      }
      else
      {
        id=bty[id];
        for(long i=1;i<=bg;i++)
          ban[i]+=bbc[i][id]*z;
        for(long i=1;i<=sm;i++)
          san[i]+=crs[id][i]*z;
      }
    }
  }
  return 0;
}