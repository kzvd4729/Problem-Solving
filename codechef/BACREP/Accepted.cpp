/****************************************************************************************
*  @author: kzvd4729                                         created: 10-10-2019 12:59:42                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.86 sec                                        memory_used: 195.9M                               
*  problem: https://www.codechef.com/OCT19A/problems/BACREP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
vector<long>adj[N+2],qr[N+2];
vector<pair<long,long> >up[N+2],ans;
long con,leaf[N+2],lev[N+2];
long bit[N+N+2];
void upd(long x,long vl)
{
  for( ;x<=N+N;x+=x&-x)
    bit[x]+=vl;
}
long get(long x)
{
  long ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
void dfs(long node,long par,long h)
{
  lev[node]=h;con=max(con,h);leaf[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,h+1);leaf[node]=0;
  }
}
void dds(long node,long par)
{
  //cout<<"**"<<node<<endl;
  for(auto x:up[node])
  {
    upd(con+x.first-lev[node],x.second);
    //cout<<node<<" "<<con+x.first-lev[node]<<" "<<x.second<<endl;
  }
  for(auto x:qr[node])
  {
    if(leaf[node])ans.push_back({x,get(con+x-lev[node])});
    else ans.push_back({x,get(con+x-lev[node])-get(con+x-lev[node]-1)});
  }
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dds(x,node);
  }
  for(auto x:up[node])
    upd(con+x.first-lev[node],-x.second);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,q;cin>>n>>q;
  for(long i=1;i<n;i++)
  {
    long u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1,0);con++;
//  for(long i=1;i<=n;i++)
//    cout<<lev[i]<<" -- ";
//  cout<<endl;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;
    up[i].push_back({0,x});
  }
  for(long i=1;i<=q;i++)
  {
    char c;cin>>c;
    if(c=='+')
    {
      long v,k;cin>>v>>k;
      up[v].push_back({i,k});
    }
    else
    {
      long v;cin>>v;
      qr[v].push_back(i);
    }
  }
  dds(1,-1);
  sort(ans.begin(),ans.end());
  for(auto x:ans)
    cout<<x.second<<"\n";
  return 0;
}