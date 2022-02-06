/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/28/2018 23:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 576 ms                                          memory_used: 18800 KB                             
*  problem: https://codeforces.com/contest/1043/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e5;
long aqm[N+2],bqm[N+2],ans[N+2];
pair<long,long>pp[N+2];
struct data
{
  long a,b,id;
}aa[N+2];
bool cmp(data A,data B)
{
  return (A.a-A.b)<(B.a-B.b);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,m;cin>>n>>m;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i].a>>aa[i].b;
    pp[i]={aa[i].a,aa[i].b};
    aa[i].id=i;
  }
  sort(aa+1,aa+n+1,cmp);
  for(long i=1;i<=n;i++)
    aqm[i]=aqm[i-1]+aa[i].a;
  for(long i=1;i<=n;i++)
    bqm[i]=bqm[i-1]+aa[i].b;
  for(long i=1;i<=n;i++)
    ans[aa[i].id]=aqm[i-1]+aa[i].b*(i-1)+bqm[n]-bqm[i]+aa[i].a*(n-i);
  while(m--)
  {
    long u,v;cin>>u>>v;
    long bs=min(pp[u].first+pp[v].second,pp[v].first+pp[u].second);
    ans[u]-=bs;ans[v]-=bs;
  }
  for(long i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}