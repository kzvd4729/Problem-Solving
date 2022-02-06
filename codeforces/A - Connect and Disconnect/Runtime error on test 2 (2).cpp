/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2019 17:55                        
*  solution_verdict: Runtime error on test 2                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7700 KB                              
*  problem: https://codeforces.com/gym/100551/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int track[N+2],par[N+2],sz[N+2],com,ans[N+2];
map<pair<int,int>,vector<pair<int,int> > >mp;
vector<pair<int,int> >seg[5*N+2];
vector<int>qr;
void add(int node,int lo,int hi,int lt,int rt,pair<int,int>p)
{
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].push_back(p);return ;
  }
  int md=(lo+hi)/2;
  add(node*2,lo,md,lt,rt,p);
  add(node*2+1,md+1,hi,lt,rt,p);
}
int get(int x)
{
  if(x==par[x])return x;
  return get(par[x]);
}
stack<vector<int> >st;
void rollBack(int now)
{
  while(st.size()>now)
  {
    vector<int>v=st.top();st.pop();
    par[v[0]]=v[0];par[v[1]]=v[1];
    sz[v[0]]=v[2];sz[v[1]]=v[3];
    com++;
  }
}
void divide(int node,int lo,int hi)
{
  vector<int>v(4);int now=st.size();
  for(auto x:seg[node])
  {
    int r1=get(x.first),r2=get(x.second);
    if(r1==r2)continue;
    if(sz[r1]>sz[r2])swap(r1,r2);
    v={r1,r2,sz[r1],sz[r2]};
    par[r1]=r2;sz[r2]+=sz[r1];
    st.push(v);com--;
  }
  if(lo==hi)
  {
    if(track[lo])ans[qr[track[lo]-1]]=com;
    rollBack(now);return ;
  }
  int md=(lo+hi)/2;
  divide(node*2,lo,md);divide(node*2+1,md+1,hi);
  rollBack(now);
}
int main()
{
  freopen("connect.in","r",stdin);
  freopen("connect.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;int cnt=0;
  for(int i=1;i<=q;i++)
  {
    char c;cin>>c;
    if(c=='?')track[i]=qr.size()+1,qr.push_back(++cnt);
    else
    {
      int u,v;cin>>u>>v;if(u>v)swap(u,v);
      if(c=='+')mp[{u,v}].push_back({i,q});
      else mp[{u,v}].back().second=i;
    }
  }
  com=n;
  for(auto x:mp)
  {
    for(auto z:x.second)
    {
      add(1,1,q,z.first,z.second,x.first);
      //cout<<z.first<<" --> "<<z.second<<" "<<x.first.first<<" "<<x.first.second<<endl;
    }
  }
  for(int i=1;i<=n;i++)par[i]=i,sz[i]=1;
  divide(1,1,q);
  for(int i=1;i<=cnt;i++)
    cout<<ans[i]<<"\n";
  return 0;
}