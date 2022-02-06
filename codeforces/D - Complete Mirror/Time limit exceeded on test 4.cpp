/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/15/2020 19:49                        
*  solution_verdict: Time limit exceeded on test 4           language: GNU C++17                               
*  run_time: 1000 ms                                         memory_used: 60500 KB                             
*  problem: https://codeforces.com/contest/1182/problem/D
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
const int mod=1000001011,b=1204003;
int hsh[N+2],sub[N+2],mx[N+2],mn[N+2],ds[N+2];
vector<int>adj[N+2];
map<int,int>mp[N+2];
bool ck(int node,int par)
{
  int mt=0;//if(mp[node].count(par))return false;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(!ck(x,node))return mp[node][par]=false;
    if(mt==0)mt=hsh[x];
    else if(mt!=hsh[x])return mp[node][par]=false;
  }
  hsh[node]=(mt*1LL*b+adj[node].size())%mod;
  return true;
}
void kill(int x,int a,int b)
{
  if(ck(x,-1))
  {
    //cout<<a<<" "<<b<<endl;
    if(a!=b)assert(0);
    cout<<x<<endl,exit(0);
  }
}
void dfs(int node,int par)
{
  sub[node]=1;mn[node]=mod;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);sub[node]+=sub[x];
    mx[node]=max(mx[node],mx[x]+1);
    mn[node]=min(mn[node],mn[x]+1);
  }
  if(mn[node]==mod)mn[node]=0;
}
void dds(int node,int par,int sz,int mxx,int mnn)
{
  //cout<<node<<" ** "<<mxx<<" "<<mnn<<endl;
  int f=1;//if(mxx!=mnn)f=0;
  //if(mx[node]!=mxx)f=0;
  //cout<<node<<" "<<mx[node]<<"**"<<mxx<<endl;
  //if(mn[node]!=mnn)f=0;
  multiset<int>a,b;a.insert(-mod);b.insert(mod);
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(sub[x]!=sz)f=0;
     a.insert(mx[x]);b.insert(mn[x]);
  }
  if(f&&sz)kill(node,mxx,mnn);if(mnn==mod)mnn=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    a.erase(a.find(mx[x]));b.erase(b.find(mn[x]));
    dds(x,node,sz+sub[node]-sub[x],max(mxx+1,(int)(*a.rbegin())+2),min(mnn+1,(int)(*b.begin())+2));
    a.insert(mx[x]);b.insert(mn[x]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  //for(int i=1;i<=n;i++)if(ck(i,-1))cout<<i<<endl,exit(0);
  dfs(1,-1);//for(int i=1;i<=n;i++)cout<<mx[i]<<" "<<mn[i]<<endl;
  dds(1,-1,0,0,mod);kill(1,0,0);
  cout<<-1<<endl;
  return 0;
}