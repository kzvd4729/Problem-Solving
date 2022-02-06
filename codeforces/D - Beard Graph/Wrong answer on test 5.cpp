/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2018 18:41                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 12900 KB                             
*  problem: https://codeforces.com/contest/165/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=3e5;
int n,bit[N+2],tim,ent[N+2],ext[N+2],color[N+2];
int anc[N+2],lvl[N+2];pair<int,int>pp[N+2];
vector<int>adj[N+2];
void upd(int x,int vl)
{
  for( ;x<=n;x+=x&-x)
    bit[x]+=vl;
}
int qry(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret+=bit[x];
  return ret;
}
void dfs(int node,int par,int lv)
{
  ent[node]=++tim;upd(ent[node],1);
  lvl[node]=lv;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,lv+1);
  }
  ext[node]=tim;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    pp[i]={u,v};
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int mx=0,rt;
  for(int i=1;i<=n;i++)
  {
    if(adj[i].size()>mx)
    {
      mx=adj[i].size();
      rt=i;
    }
  }
  dfs(rt,-1,0);
  for(auto x:adj[rt])
  {
    for(int i=ent[x];i<=ext[x];i++)
      anc[i]=x;
  }
  //cout<<ent[rt]<<endl;
  int q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int id;cin>>id;
      if(ent[pp[id].first]>ent[pp[id].second])
        swap(pp[id].first,pp[id].second);
      upd(ent[pp[id].second],1);color[pp[id].second]=1;
    }
    else if(ty==2)
    {
      int id;cin>>id;
      if(ent[pp[id].first]>ent[pp[id].second])
        swap(pp[id].first,pp[id].second);
      upd(ent[pp[id].second],-1);color[pp[id].second]=0;
    }
    else
    {
      int a,b;cin>>a>>b;
      if(ent[a]>ent[b])swap(a,b);
      if(a==b)cout<<0<<endl;
      else if(ent[a]==1)
      {
        //cout<<"here"<<endl;
        if(qry(ent[b])-qry(ent[anc[ent[b]]]-1)==lvl[b])
          cout<<lvl[b]<<endl;
        else cout<<-1<<endl;
      }
      else if(anc[a]==anc[b])
      {
        int sum=qry(ent[b])-qry(ent[a]);
        if(sum==ent[b]-ent[a])
          cout<<sum<<endl;
        else cout<<-1<<endl;
      }
      else
      {
        //cout<<"here"<<endl;
        //cout<<anc[ent[a]]<<" "<<anc[ent[b]]<<endl;
        int sum=qry(ent[a])-qry(ent[anc[ent[a]]]-1)+qry(ent[b])-qry(ent[anc[ent[b]]]-1);
        //cout<<sum<<endl;
        if(sum==lvl[b]+lvl[a])
          cout<<sum<<endl;
        else cout<<-1<<endl;
      }
    }
  }
  return 0;
}