/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/12/2019 20:59                        
*  solution_verdict: Runtime error on test 2                 language: GNU C++14                               
*  run_time: 170 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/gym/100551/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
 /*
offline version with dsu rollback.
there have to be same number of add and remove operation
for every edge.
*/
struct dynamicConnectivity
{
  vector<int>par,sz,ty,uu,vv,oth;
  stack<int>st;map<pair<int,int>,int>mp;
  int com;
  void clean(int n,int q)//nodes and queries
  {
    par.resize(n+1),sz.resize(n+1),ty.resize(q+1);
    uu.resize(q+1),vv.resize(q+1),oth.resize(q+1);
    for(int i=0;i<=n;i++)par[i]=i,sz[i]=1;
    for(int i=0;i<=q;i++)ty[i]=0;
    while(st.size())st.pop();com=n;
    mp.clear();
  }
  int get(int x)
  {
    while(x!=par[x])x=par[x];//no path compression
    return x;
  }
  void add(int u,int v)
  {
    u=get(u),v=get(v);if(u==v)return ;
    if(sz[u]>sz[v])swap(u,v);
    sz[v]+=sz[u];par[u]=v;//maintain logn height of the tree
    st.push(u);//u is connected with par[u]
    com--;//number of connected component is decreased by 1
  }
  void rollBack(int t)//stack size was t before the recursion
  {
    while(st.size()>t)
    {
      int u=st.top();st.pop();
      sz[par[u]]-=sz[u];par[u]=u;
      com++;//number of connected component is increased by 1
    }
  }
  void divide(int lo,int hi)
  {
    if(lo==hi)
    {
      if(ty[lo]==3)//query operation
      {
        cout<<com<<"\n";
        //answer
      }
      return ;
    }
    int md=(lo+hi)/2,sz=st.size();
    for(int i=md+1;i<=hi;i++)
      if(oth[i]<lo)add(uu[i],vv[i]);
    divide(lo,md);rollBack(sz);
    for(int i=lo;i<=hi;i++)
      if(oth[i]>hi)add(uu[i],vv[i]);
    divide(md+1,hi);rollBack(sz);
  }
  //assumed that there won't be any multi-edge
  void addQuery(int t,int u,int v,int i)//1 for add, 2 for remove
  {
    ty[i]=t,uu[i]=u,vv[i]=v;
    if(uu[i]>vv[i])swap(uu[i],vv[i]);
     pair<int,int>p={u,v};
    if(t==1)mp[p]=i;
    else
    {
      oth[i]=mp[p];//when the add operation was done
      oth[oth[i]]=i;//rgt[i] is is active till i-1;
      mp.erase(p);//edge is deleted
    }
  }
};
int main()
{
  freopen("connect.in","r",stdin);
  freopen("connect.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  vector<vector<int> >vc;set<pair<int,int> >st;
  while(q--)
  {
    char ty;cin>>ty;int u=0,v=0;
    if(ty=='?')vc.push_back({3,0,0});
    else
    {
      cin>>u>>v;if(u>v)swap(u,v);
      if(ty=='+')st.insert({u,v}),vc.push_back({1,u,v});
      else st.erase({u,v}),vc.push_back({2,u,v});
    }
  }
  for(auto x:st)
    vc.push_back({2,x.first,x.second});
  dynamicConnectivity dn;dn.clean(n,vc.size());
  for(int i=0;i<vc.size();i++)
    dn.addQuery(vc[i][0],vc[i][1],vc[i][2],i+1);
  dn.divide(1,vc.size());
  return 0;
}