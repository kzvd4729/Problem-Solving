/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/11/2020 19:39                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 152600 KB                            
*  problem: https://codeforces.com/contest/1168/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=150000;
vector<int>adj[N+2];
int tim,ent[N+2],ext[N+2],n;
char ch[N+2];
vector<int>seg[4*N+8];
int lz[4*N+8][27+2];
int con(char c)
{
  if(c>='a'&&c<='z')return c-'a';
  else return 26;
}
void upd(int node,int lo,int hi,int id,vector<int>v)
{
  if(lo==hi){seg[node]=v;return;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,v);
  else upd(node*2+1,md+1,hi,id,v);
  seg[node].resize(27);
  for(int i=0;i<27;i++)seg[node][i]=max(seg[node*2][i],seg[node*2+1][i]);
}
void tooLazy(int node,int lo,int hi)
{
  for(int i=0;i<27;i++)
  {
    seg[node][i]+=lz[node][i];
    if(lo!=hi)
    {
      lz[node*2][i]+=lz[node][i];
      lz[node*2+1][i]+=lz[node][i];
    }
    lz[node][i]=0;
  }
}
void upd2(int node,int lo,int hi,int lt,int rt,int id,int vl)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return;
  if(lo>=lt&&hi<=rt)
  {
    lz[node][id]+=vl;tooLazy(node,lo,hi);
    return;
  }
  int md=(lo+hi)/2;
  upd2(node*2,lo,md,lt,rt,id,vl);
  upd2(node*2+1,md+1,hi,lt,rt,id,vl);
  seg[node].resize(27);
  for(int i=0;i<27;i++)seg[node][i]=max(seg[node*2][i],seg[node*2+1][i]);
}
set<int>st;
vector<int>inc(vector<int>v,char c)
{
  v[con(c)]++;return v;
}
void dfs(int node,int d,vector<int>v)
{
  ent[node]=++tim;
  for(auto x:adj[node])
    dfs(x,d+1,inc(v,ch[x]));
   ext[node]=tim;
   if(adj[node].size())return;
  upd(1,1,n,tim,v);st.insert(d);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int q;cin>>n>>q;
  for(int i=2;i<=n;i++)
  {
    char c;int x;cin>>x>>c;
    adj[x].push_back(i);ch[i]=c;
  }
  for(int i=0;i<4*N+8;i++)seg[i].resize(27,0);
  vector<int>v(27,0);dfs(1,0,v);
   if(st.size()!=1)assert(0);
  int d=*st.begin();
   while(q--)
  {
    int a;char c;cin>>a>>c;
    upd2(1,1,n,ent[a],ext[a],con(ch[a]),-1);ch[a]=c;
    upd2(1,1,n,ent[a],ext[a],con(ch[a]),+1);
         int sm=0;
    for(int i=0;i<26;i++)sm+=seg[1][i];
     if(sm>d)cout<<"Fou\n";
    else
    {
      long ans=0;
      for(int i=0;i<26;i++)ans+=1LL*(seg[1][i]+d-sm)*(i+1);
       cout<<"Shi "<<ans<<"\n";
    }
  }
  return 0;
}