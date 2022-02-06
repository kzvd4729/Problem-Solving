/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2019 22:49                        
*  solution_verdict: Time limit exceeded on test 13          language: GNU C++14                               
*  run_time: 5000 ms                                         memory_used: 10300 KB                             
*  problem: https://codeforces.com/contest/1217/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,sq=420;
int par[N+2],par2[N+2];
vector<vector<int> >qry;
map<pair<int,int>,pair<int,int> >mp;
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int get2(int x)
{
  if(x==par2[x])return x;
  return par2[x]=get2(par2[x]);
}
void add(int u,int v)
{
  int p1=get(u),p2=get(v);
  if(p1!=p2)par[p1]=p2;
}
void add2(int u,int v)
{
  int p1=get2(u),p2=get2(v);
  if(p1!=p2)par2[p1]=p2;
}
void upd(int x)
{
  int r=get(x);par2[x]=r,par2[r]=r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;qry.resize(q);
   vector<pair<int,int> >ed;int last=0;
  for(int bl=0; ;bl++)
  {
    int l=bl*sq,r=min((bl+1)*sq,q)-1;if(l>r)break;
     vector<pair<int,int> >modi;
    for(int i=l;i<=r;i++)
    {
      int ty,u,v;cin>>ty>>u>>v;
      if(u>v)swap(u,v);qry[i]={ty,u,v};
      modi.push_back({u,v});
      u++,v++;if(u>n)u=1;if(v>n)v=1;if(u>v)swap(u,v);
      modi.push_back({u,v});
    }
    sort(modi.begin(),modi.end());
    modi.erase(unique(modi.begin(),modi.end()),modi.end());
    for(int i=1;i<=n;i++)par[i]=i;
    for(auto x:ed)
    {
      if(!binary_search(modi.begin(),modi.end(),x))
        if(mp[x].second>r)add(x.first,x.second);
    }
    for(int i=l;i<=r;i++)
    {
      int u=qry[i][1],v=qry[i][2];
      u+=last,v+=last;if(u>n)u=1;if(v>n)v=1;if(u>v)swap(u,v);
      if(qry[i][0]==1)
      {
        ed.push_back({u,v});
        if(mp.count({u,v}))
        {
          if(mp[{u,v}].second==q)mp[{u,v}].second=i;
          else mp[{u,v}]={i,q};
        }
        else mp[{u,v}]={i,q};
      }
      else
      {
        for(auto x:modi)
        {
          if(mp.count(x)&&mp[x].second>i)
            upd(x.first),upd(x.second);
        }
        upd(u),upd(v);
        for(auto x:modi)
        {
          if(mp.count(x)&&mp[x].second>i)
          {
            add2(x.first,x.second);
            //if(i==7)cout<<x.first<<" --> "<<x.second<<endl;
          }
        }
        last=(get2(u)==get2(v));
        cout<<last;
      }
    }
  }
  cout<<endl;
  return 0;
}