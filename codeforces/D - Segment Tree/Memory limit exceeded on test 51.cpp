/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/19/2019 21:49                        
*  solution_verdict: Memory limit exceeded on test 51        language: GNU C++14                               
*  run_time: 1793 ms                                         memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/1278/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
pair<int,int>pp[N+2];
 int sp[N+2][20+2];
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=pp[i].second;//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))<=n)
        sp[i][j]=max(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  return max(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
int vis[N+2],cnt;
vector<int>adj[N+2];
void dfs(int node)
{
  vis[node]=1;cnt++;
  for(auto x:adj[node])
    if(!vis[x])dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+n+1);build(n);
    // for(int i=1;i<=n;i++)
  //   cout<<pp[i].first<<" ** "<<pp[i].second<<endl;
    int ed=0;
  for(int i=1;i<=n;i++)
  {
    int pt=i+1;
    while(pt<=n)
    {
      int lo=pt,hi=n,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(pp[md].first>pp[i].second)hi=md;
        else if(get(pt,md)>pp[i].second)hi=md;
        else lo=md;
      }
      int tr=-1;
      for(md=lo;md<=hi;md++)
      {
        if(pp[md].first>pp[i].second)break;
        else if(get(pt,md)>pp[i].second){tr=md;break;}
      }
      if(tr==-1)break;ed++;if(ed==n)break;
      adj[i].push_back(tr);pt=tr+1;
      adj[tr].push_back(i);
     // cout<<i<<" --> "<<tr<<endl;
    }
  }
  if(ed==n)cout<<"NO\n",exit(0);
   dfs(1);if(cnt!=n)cout<<"NO\n",exit(0);
  cout<<"YES\n";
  return 0;
}