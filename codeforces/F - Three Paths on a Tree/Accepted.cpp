/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/22/2020 21:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 389 ms                                          memory_used: 31600 KB                             
*  problem: https://codeforces.com/contest/1294/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int sub[N+2],fav[N+2],on,tw,th,mx;
vector<int>adj[N+2];
void dfs(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x==par)continue;dfs(x,node);
    if(sub[x]+1>sub[node])
    {
      sub[node]=sub[x]+1;fav[node]=fav[x];
    }
  }
  if(!fav[node])fav[node]=node;
}
void dds(int node,int par,int sb,int fv)
{
  multiset<pair<int,int> >st;
  st.insert({0,0});st.insert({0,0});
  st.insert({sb,fv});
   for(auto x:adj[node])
  {
    if(x==par)continue;
    st.insert({sub[x]+1,fav[x]});
  }
   pair<int,int>a=*st.rbegin();st.erase(st.find(a));
  pair<int,int>b=*st.rbegin();st.erase(st.find(b));
  pair<int,int>c=*st.rbegin();st.erase(st.find(c));
   if(a.first+b.first+c.first>mx)
  {
    mx=a.first+b.first+c.first;
    on=a.second,tw=b.second,th=c.second;
    //cout<<mx<<" ** "<<node<<endl;
  }
   st.insert(a),st.insert(b),st.insert(c);
  for(auto x:adj[node])
  {
    if(x==par)continue;
    st.erase(st.find({sub[x]+1,fav[x]}));
     pair<int,int>p=*st.rbegin();
    dds(x,node,p.first+1,p.second);
    st.insert({sub[x]+1,fav[x]});
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
  dfs(1,-1);dds(1,-1,0,1);
  if(on==0)
  {
    if(tw!=1&&th!=1)on=1;
    else if(tw!=2&&th!=2)on=2;
    else if(tw!=3&&th!=3)on=3;
  }
  if(tw==0)
  {
    if(on!=1&&th!=1)tw=1;
    else if(on!=2&&th!=2)tw=2;
    else if(on!=3&&th!=3)tw=3;
  }
  if(th==0)
  {
    if(tw!=1&&on!=1)th=1;
    else if(tw!=2&&on!=2)th=2;
    else if(tw!=3&&on!=3)th=3;
  }
  cout<<mx<<endl<<on<<" "<<tw<<" "<<th<<endl;
  return 0;
}