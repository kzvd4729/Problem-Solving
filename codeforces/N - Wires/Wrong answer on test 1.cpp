/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/27/2019 19:37                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 19700 KB                             
*  problem: https://codeforces.com/contest/1250/problem/N
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int par[N+2],uu[N+2],vv[N+2],ed[N+2],deg[N+2];
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<int>vc;
    for(int i=1;i<=n;i++)
    {
      cin>>uu[i]>>vv[i];
      vc.push_back(uu[i]);vc.push_back(vv[i]);
    }
    sort(vc.begin(),vc.end());
    vc.erase(unique(vc.begin(),vc.end()),vc.end());
     map<int,int>cn,rv;int sz=0;
    for(auto x:vc)
    {
      cn[x]=++sz;rv[sz]=x;
    }
     for(int i=1;i<=n;i++)uu[i]=cn[uu[i]],vv[i]=cn[vv[i]];
    for(int i=1;i<=sz;i++)par[i]=i,ed[i]=0,deg[i]=0;
 //    cout<<endl;
//    for(int i=1;i<=n;i++)
//      cout<<uu[i]<<"-->"<<vv[i]<<endl;
     vector<int>ex;
    for(int i=1;i<=n;i++)
    {
      int r1=get(uu[i]),r2=get(vv[i]);
      if(r1==r2)ex.push_back(i);
      else par[r1]=r2;
      deg[uu[i]]++,deg[vv[i]]++;
    }
//    for(int i=1;i<=sz;i++)
//      cout<<deg[i]<<" ";
//    cout<<endl;
    vector<int>rt;
    for(int i=1;i<=sz;i++)
      rt.push_back(get(i));
    sort(rt.begin(),rt.end());
    rt.erase(unique(rt.begin(),rt.end()),rt.end());
     for(auto x:ex)
    {
      int r=get(uu[x]);
      if(!ed[r])ed[r]=x;
    }
    for(int i=1;i<=n;i++)
    {
      if(deg[uu[i]]==1||deg[vv[i]]==1)
      {
        int r=get(uu[i]);
        if(!ed[r])ed[r]=i;
      }
    }
    cout<<rt.size()-1<<"\n";
    for(int i=1;i<rt.size();i++)
    {
      int nm=ed[rt[i]];
      cout<<nm<<" ";
      if(deg[uu[nm]]==0)cout<<rv[uu[nm]]<<" "<<rv[rt[i-1]]<<"\n";
      else cout<<rv[vv[nm]]<<" "<<rv[rt[i-1]]<<"\n";
    }
  }
  return 0;
}