/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2019 19:43                        
*  solution_verdict: Runtime error on test 12                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 9400 KB                              
*  problem: https://codeforces.com/gym/102215/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5,inf=1e9;
 int tr;
struct treap
{
  int lt,rt,dt,pri,vl,mx;
}bst[N+2];
void cal(int node)
{
  bst[node].mx=max(bst[node].vl,max(bst[bst[node].lt].mx,bst[bst[node].rt].mx));
}
pair<int,int>splitbyValue(int node,int vl)
{
  if(!node)return {0,0};pair<int,int>p;
  if(bst[node].dt<=vl)
  {
    p=splitbyValue(bst[node].rt,vl);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
  else
  {
    p=splitbyValue(bst[node].lt,vl);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
}
int join(int lt,int rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(bst[lt].pri>=bst[rt].pri)
  {
    bst[lt].rt=join(bst[lt].rt,rt);
    cal(lt);return lt;
  }
  else
  {
    bst[rt].lt=join(lt,bst[rt].lt);
    cal(rt);return rt;
  }
}
bool cmp(vector<int>a,vector<int>b)
{
  if(a[1]!=b[1])return a[1]<b[1];
  return a[0]>b[0];
}
void purify(vector<vector<int> >&v)
{
  sort(v.begin(),v.end(),cmp);
  vector<vector<int> >u;
  for(auto x:v)
  {
    if(u.size()==0)u.push_back(x);
    else if(u.back()[1]!=x[1])u.push_back(x);
  }
  v=u;
}
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;vector<vector<int> >v(n);
  for(int i=0;i<n;i++)
  {
    v[i].resize(3);cin>>aa[i+1]>>bb[i+1];
    v[i][0]=aa[i+1],v[i][1]=bb[i+1];
    v[i][2]=i+1;
  }
  sort(v.begin(),v.end());
   // for(auto x:v)
  //   cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
   int ans=0,a=1,b=2;
   for(int i=0;i<n-1;i++)
  {
    if(v[n-1][0]>=v[i][1]&&v[i][0]>ans)
      ans=v[i][0],a=v[i][2];
  }
  if(v[n-2][0]>=v[n-1][1]&&v[n-1][0]>ans)ans=v[n-1][0],a=v[n-1][2];
  //cout<<ans<<endl;
   purify(v);
   vector<pair<int,int> >at,ht;
  for(auto x:v)at.push_back({x[0],x[2]});
  for(auto x:v)ht.push_back({x[1],x[2]});
   sort(at.begin(),at.end());sort(ht.begin(),ht.end());
   reverse(ht.begin(),ht.end());reverse(at.begin(),at.end());
  // for(auto x:ht)cout<<x.first<<" ";cout<<endl;
  // for(auto x:at)cout<<x.first<<" ";cout<<endl;
  //cout<<ans<<endl;
  int root=0,pt=0;
  for(auto x:ht)
  {
    while(pt<at.size())
    {
      if(at[pt].first<x.first)break;
      //cout<<"*"<<bb[at[pt].second]<<endl;
      bst[++tr]={0,0,bb[at[pt].second],rand(),at[pt].first,at[pt].first};
       pair<int,int>p=splitbyValue(root,bb[at[pt].second]);
       root=join(p.first,tr);root=join(root,p.second);
       pt++;
    }
     pair<int,int>p=splitbyValue(root,aa[x.second]);
     pair<int,int>p1=splitbyValue(p.first,x.first-1);
     pair<int,int>p2=splitbyValue(p1.second,x.first);
     int mx=max(bst[p1.first].mx,bst[p2.second].mx);
     if(mx&mx+aa[x.second]>ans)
    {
      ans=max(bst[p1.first].mx,bst[p2.second].mx)+aa[x.second];
      a=x.second;
    }
    root=join(p2.first,p2.second);
    root=join(p1.first,root);root=join(root,p.second);
  }
  cout<<ans<<endl;
  //cout<<a<<endl;
  for(int i=1;i<=n;i++)
  {
    if(i==a)continue;
    int now=0;
     if(aa[i]>=bb[a])now+=aa[a];
    if(aa[a]>=bb[i])now+=aa[i];
     if(ans==now)cout<<i<<" "<<a<<endl,exit(0);
  }
  assert(0);
  return 0;
}