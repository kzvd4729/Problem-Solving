/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/08/2021 23:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 498 ms                                          memory_used: 96500 KB                             
*  problem: https://codeforces.com/contest/1467/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int a[N+2];
void compress(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(a[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
   for(int i=1;i<=n;i++)a[i]=mp[a[i]];
}
int bit[N+2];
void upd(int x,int vl)
{
  for( ;x<=N;x+=x&-x)bit[x]+=vl;
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
vector<int>ad[N+2];
int tim,ent[N+2],ext[N+2],ch[N+2],ln[N+2],vs[N+2];
void dfs(int nd,int pr)
{
  ent[nd]=++tim;ln[tim]=nd;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd);
  }
  ext[nd]=tim;
}
set<int>st[N+2];
void dfs2(int nd,int pr)
{
  if((int)st[a[nd]].size())
  {
    int dl=ln[*st[a[nd]].rbegin()];
    vs[dl]=1;
     upd(ent[1],1);upd(ext[1]+1,-1);
    upd(ent[ch[dl]],-1);upd(ext[ch[dl]]+1,1);
  }
  st[a[nd]].insert(ent[nd]);
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    ch[nd]=x;dfs2(x,nd);
  }
  st[a[nd]].erase(ent[nd]);
}
int mn[N+2],mx[N+2],ck[N+2];
void dfs3(int nd,int pr)
{
  if(mn[a[nd]]<ent[nd]||mx[a[nd]]>ext[nd])
  {
    upd(ent[nd],1);upd(ext[nd]+1,-1);
  }
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs3(x,nd);
  }
}
bool dfs4(int nd,int pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    vs[nd]|=dfs4(x,nd);
  }
  return vs[nd];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];compress(n);
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);ad[v].push_back(u);
  }
  dfs(1,-1);dfs2(1,-1);
  for(int i=1;i<=n;i++)mn[i]=1e9;
   for(int i=1;i<=n;i++)
  {
    mn[a[i]]=min(mn[a[i]],ent[i]);
    mx[a[i]]=max(mx[a[i]],ent[i]);
  }
  //cout<<"here"<<endl;
   dfs3(1,-1);dfs4(1,-1);int cnt=0;
  for(int i=1;i<=n;i++)cnt+=((get(ent[i])==0)&&(vs[i]==0));
   cout<<cnt<<endl;
   return 0;
}