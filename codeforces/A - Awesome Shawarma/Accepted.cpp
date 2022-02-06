/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 00:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1512 ms                                         memory_used: 10700 KB                             
*  problem: https://codeforces.com/gym/101991/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int l,r,n;long ans;
int tot,mark[N+2],sz[N+2];
vector<int>adj[N+2];
 int bit[N+2];
void upd(int x,int vl)
{
  x++;
  for( ;x<=N;x+=(x&-x))
    bit[x]+=vl;
}
int get(int x)
{
  x++;if(x<=0)return 0;
  int sum=0;
  for( ;x>0;x-=(x&-x))
    sum+=bit[x];
  return sum;
}
 void reckon(int node,int par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    reckon(x,node);sz[node]+=sz[x];
  }
}
int findCenter(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    if(sz[x]>tot/2)return findCenter(x,node);
  }
  return node;
}
void add(int node,int par,int lv)
{
  upd(lv,1);
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    add(x,node,lv+1);
  }
}
void cal(int node,int par,int lv)
{
  int lt=n-1-lv-r,rt=n-1-lv-l;
  //cout<<node<<" "<<lv<<" "<<lt<<" "<<rt<<endl;
  ans+=get(rt)-get(lt-1);
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    cal(x,node,lv+1);
  }
}
void rem(int node,int par,int lv)
{
  upd(lv,-1);
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    rem(x,node,lv+1);
  }
}
void centroid(int node,int par)
{
  tot=0;reckon(node,-1);
  int center=findCenter(node,-1);
  mark[center]=1;
   add(center,-1,0);
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    rem(x,-1,1);cal(x,-1,1);
  }
  upd(0,-1);
  /*cout<<ans<<endl;
  exit(0);*/
   for(auto x:adj[center])
  {
    if(mark[x])continue;
    centroid(x,center);
  }
}
 int main()
{
  freopen("awesome.in","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
    {
      adj[i].clear(),mark[i]=0;
    }
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    ans=0;centroid(1,-1);
    cout<<ans<<"\n";
  }
  return 0;
}