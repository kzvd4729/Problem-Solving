/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-13 17:57:51                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 150                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11987
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,m,parent[N+N+2],sz[N+N+2];
long sum[N+N+2];
long find_parent(long node)
{
  if(node==parent[node])return node;
  return parent[node]=find_parent(parent[node]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>n>>m)
  {
    memset(parent,0,sizeof(parent));
    memset(sz,0,sizeof(sz));
    memset(sum,0,sizeof(sum));
    for(long i=1;i<=n;i++)
    {
      parent[i]=n+i;
      parent[n+i]=n+i;
      sz[n+i]=1;sum[n+i]=i;
    }
    while(m--)
    {
      long ty;cin>>ty;
      if(ty==1)
      {
        long p,q;cin>>p>>q;
        long r1=find_parent(p);
        long r2=find_parent(q);
        if(r1==r2)continue;
        sz[r2]+=sz[r1];sum[r2]+=sum[r1];
        parent[r1]=r2;
      }
      else if(ty==2)
      {
        long p,q;cin>>p>>q;
        long r1=find_parent(p);
        long r2=find_parent(q);
        if(r1==r2)continue;
        sz[r1]--;sum[r1]-=p;
        sz[r2]++;sum[r2]+=p;
        parent[p]=r2;
      }
      else
      {
        long p;cin>>p;
        long r1=find_parent(p);
        cout<<sz[r1]<<" "<<sum[r1]<<endl;
      }
    }
  }
  return 0;
}