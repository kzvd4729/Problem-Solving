/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/11/2020 00:49                        
*  solution_verdict: Time limit exceeded on test 28          language: GNU C++14                               
*  run_time: 4000 ms                                         memory_used: 57800 KB                             
*  problem: https://codeforces.com/contest/1166/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,magic=220;
int par[N+2],dg[N+2],ans[N+2];
map<int,int>mp[N+2];
vector<vector<int> >v;
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
void add(int a,int b)
{
  //cout<<a<<" ** "<<b<<endl;
  int r1=get(a),r2=get(b);
  if(r1!=r2)par[r1]=r2;
}
void solve2(int n,int nd)
{
  for(int i=1;i<=n;i++)par[i]=i,mp[i].clear();int id=-1;
  for(auto x:v)
  {
    id++;
    if(x[0]==1)
    {
      int a=x[1],b=x[2],c=x[3];
      if(a==nd||b==nd){add(a,b);continue;}
      if(mp[a].count(c))add(mp[a][c],b);
      else mp[a][c]=b;
       if(mp[b].count(c))add(mp[b][c],a);
      else mp[b][c]=a;
    }
    else
    {
      int a=x[1],b=x[2];if(b!=nd)continue;
      ans[id]|=(get(a)==get(b));
    }
  }
}
void solve1(int n)
{
  for(int i=1;i<=n;i++)par[i]=i;int id=-1;
  for(auto x:v)
  {
    id++;
    if(x[0]==1)
    {
      int a=x[1],b=x[2],c=x[3];
      if(mp[a].count(c))add(mp[a][c],b);
      else mp[a][c]=b;
       if(mp[b].count(c))add(mp[b][c],a);
      else mp[b][c]=a;
    }
    else
    {
      int a=x[1],b=x[2];
      int f=0;int cm=get(a);
      if(cm==get(b))f=1;
       //cout<<a<<" "<<b<<" "<<f<<endl;
       if(dg[b]<=magic)
      {
        for(auto x:mp[b])
        {
          if(f)break;
          if(cm==get(x.second))f=1;
        }
      }
      ans[id]|=f;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,c,q;cin>>n>>m>>c>>q;
  for(int i=1;i<=m;i++)
  {
    int a,b,c;cin>>a>>b>>c;dg[a]++,dg[b]++;
    v.push_back({1,a,b,c});
  }
  for(int i=1;i<=q;i++)
  {
    char ch;cin>>ch;int a,b,c;
    if(ch=='+')
    {
      cin>>a>>b>>c;dg[a]++,dg[b]++;
      v.push_back({1,a,b,c});
    }
    else 
    {
      cin>>a>>b;
      v.push_back({2,a,b});
    }
  }
  //cout<<v.size()<<endl;
  solve1(n);
  for(int i=1;i<=n;i++)if(dg[i]>magic)solve2(n,i);
  for(int i=0;i<v.size();i++)
  {
    if(v[i][0]==1)continue;
    if(ans[i])cout<<"Yes\n";else cout<<"No\n";
  }
  return 0;
}