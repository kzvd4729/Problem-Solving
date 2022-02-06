/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2019 22:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 38400 KB                             
*  problem: https://codeforces.com/contest/1237/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],sp[N+2][20+2],mn[N+2][20+2],nxt[N+2],ans[N+2];
void build(int n)
{
  for(int i=1;i<=n;i++)
    sp[i][0]=aa[i];//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))>n)continue;
      sp[i][j]=max(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
  for(int i=1;i<=n;i++)
    mn[i][0]=aa[i];//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      mn[i][j]=mn[i][j-1];
      if((i+(1<<(j-1)))>n)continue;
      mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  return max(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
int mnm(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  return min(mn[lt][dg],mn[rt-(1<<dg)+1][dg]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];aa[n+i]=aa[i];
    v.push_back({aa[i],i});
  }
  build(n+n);
//  for(int i=1;i<=n+n;i++)
//    cout<<aa[i]<<" ";
//  cout<<endl;
   for(int i=1;i<=n;i++)
  {
    int lo=i,hi=n+n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(get(i,md)>aa[i])hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
      if(get(i,md)>aa[i])break;
    nxt[i]=md;
  }
//  for(int i=1;i<=n;i++)
//    cout<<nxt[i]<<" ";
//  cout<<endl;
   sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
   ans[n+n+1]=-1;
  for(auto &x:v)
  {
    int id=x.second;
    int vl=(x.first-1)/2;
     //cout<<"**"<<vl<<endl;
     int lo=id,hi=nxt[id]-1,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(mnm(id,md)<=vl)hi=md;
      else lo=md;
    }
    int f=0;
    for(md=lo;md<=hi;md++)
    {
      if(mnm(id,md)<=vl)
      {
        f=1;break;
      }
    }
    if(f)
    {
      ans[id]=md-id;
      //if(ans[id]>=n)ans[id]=-1;
    }
    else
    {
      if(ans[nxt[id]]==-1)ans[id]=-1;
      else ans[id]=ans[nxt[id]]+nxt[id]-id;
      //if(ans[id]>=n)ans[id]=-1;
    }
    ans[id+n]=ans[id];
  }
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}