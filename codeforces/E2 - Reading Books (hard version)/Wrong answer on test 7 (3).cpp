/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/28/2020 22:06                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 35100 KB                             
*  problem: https://codeforces.com/contest/1374/problem/E2
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
#define long long long  
using namespace std;
const int N=1e6,inf=2e9+1;
int tr;
struct treap
{
  int lt,rt,dt,pri,sz,sm;
}bst[N+2];
void cal(int node)
{
  if(node==0)return;
  bst[node].sz=bst[bst[node].lt].sz+bst[bst[node].rt].sz+1;
  bst[node].sm=bst[bst[node].lt].sm+bst[bst[node].rt].sm+bst[node].dt;
}
//left tree will contain value <= vl.
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
pair<int,int>splitbySize(int node,int ss)
{
  if(!node)return {0,0};pair<int,int>p;
  if(bst[bst[node].lt].sz>=ss)
  {
    p=splitbySize(bst[node].lt,ss);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
  else
  {
    p=splitbySize(bst[node].rt,ss-bst[bst[node].lt].sz-1);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
}
//lt and rt are bst and max element of lt <= minimum of rt
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
int qb[N+2],qc[N+2];
vector<pair<int,int> >ta,tb,tc,td;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;vector<int>a,b,c;int root=0;
  //int lt,rt,dt,pri,sz,sm;
  for(int i=1;i<=n;i++)
  {
    int x,y,z;cin>>x>>y>>z;
    if(y&&z)a.push_back(x),ta.push_back({x,i});
    else if(y)b.push_back(x),tb.push_back({x,i});
    else if(z)c.push_back(x),tc.push_back({x,i});
    else 
    {
      bst[++tr]={0,0,x,rand(),1,x};
      pair<int,int>p=splitbyValue(root,x);
      root=join(p.first,tr);root=join(root,p.second);
       td.push_back({x,i});
    }
  }
  //cout<<bst[root].sm<<endl;
  sort(a.begin(),a.end()),sort(b.begin(),b.end()),sort(c.begin(),c.end());
    for(int i=k;i<b.size();i++)
  {
    int x=b[i];
    bst[++tr]={0,0,x,rand(),1,x};
    pair<int,int>p=splitbyValue(root,x);
    root=join(p.first,tr);root=join(root,p.second);
  }
  for(int i=k;i<c.size();i++)
  {
    int x=c[i];
    bst[++tr]={0,0,x,rand(),1,x};
    pair<int,int>p=splitbyValue(root,x);
    root=join(p.first,tr);root=join(root,p.second);
  }
  if(b.size())qb[0]=b[0];
  for(int i=1;i<b.size();i++)qb[i]=qb[i-1]+b[i];
  if(c.size())qc[0]=c[0];
  for(int i=1;i<c.size();i++)qc[i]=qc[i-1]+c[i];
   int ans=inf,pr=-2;
  if(k+k<=m&&b.size()>=k&&c.size()>=k)
  {
    int now=qb[k-1]+qc[k-1];
    pair<int,int>p=splitbySize(root,m-(k+k));
    now+=bst[p.first].sm;root=join(p.first,p.second);
     ans=now,pr=-1;
  }
  int cr=0;
  for(int i=0;i<min((int)a.size(),k);i++)
  {
    cr+=a[i];int dl=k-1-i;
    if(dl<b.size())
    {
      int x=b[dl];
      bst[++tr]={0,0,x,rand(),1,x};
      pair<int,int>p=splitbyValue(root,x);
      root=join(p.first,tr);root=join(root,p.second);
    }
    if(dl<c.size())
    {
      int x=c[dl];
      bst[++tr]={0,0,x,rand(),1,x};
      pair<int,int>p=splitbyValue(root,x);
      root=join(p.first,tr);root=join(root,p.second);
    }
    if(b.size()>=dl&&c.size()>=dl&&m>=dl+dl+i+1)
    {
      int ad1=0,ad2=0;
      if(dl)ad1=qb[dl-1],ad2=qc[dl-1];
      pair<int,int>p=splitbySize(root,m-(dl+dl+i+1));
      int now=ad1+ad2+cr+bst[p.first].sm;root=join(p.first,p.second);
      if(now<ans)ans=now,pr=i;
    }
  }
  if(ans==inf)cout<<-1<<endl,exit(0);
  cout<<ans<<endl;
   vector<int>prnt;
  sort(ta.begin(),ta.end()),sort(tb.begin(),tb.end()),sort(tc.begin(),tc.end());
  sort(td.begin(),td.end());
  pr++;
  for(int i=0;i<pr;i++)prnt.push_back(ta[i].second),m--;
  for(int i=0;i<k-pr;i++)prnt.push_back(tb[i].second),m--;
  for(int i=0;i<k-pr;i++)prnt.push_back(tc[i].second),m--;
   set<pair<int,int> >st;
  for(int i=k-pr;i<tb.size();i++)st.insert(tb[i]);
  for(int i=k-pr;i<tc.size();i++)st.insert(tc[i]);
  for(int i=0;i<td.size();i++)st.insert(td[i]);
   assert(m>=0);
  while(m)
  {
    pair<int,int>p=*st.begin();st.erase(p);prnt.push_back(p.second);
    m--;
  }
  assert(m==0);
  for(auto x:prnt)cout<<x<<" ";cout<<endl;
   return 0;
}