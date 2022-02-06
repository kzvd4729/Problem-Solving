/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2020 23:22                        
*  solution_verdict: Runtime error on test 7                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 16500 KB                             
*  problem: https://codeforces.com/contest/377/problem/D
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=3e5;
int lazy[4*N+8];pair<int,int>sg[4*N+8];
void tooLazy(int node,int lo,int hi)
{
  sg[node].first+=lazy[node];
  if(lo!=hi)lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
  lazy[node]=0;
}
void build(int nd,int lo,int hi)
{
  if(lo==hi){sg[nd]={0,lo};return ;}
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
  sg[nd]=max(sg[nd*2],sg[nd*2+1]);
}
void upd(int node,int lo,int hi,int lt,int rt,int ad)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=ad;tooLazy(node,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,ad);upd(node*2+1,md+1,hi,lt,rt,ad);
  sg[node]=max(sg[node*2],sg[node*2+1]);
}
pair<int,int>get(int node,int lo,int hi,int lt,int rt)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return {-N,0};
  if(lo>=lt&&hi<=rt)return sg[node];
  int md=(lo+hi)/2;
  return max(get(node*2,lo,md,lt,rt),get(node*2+1,md+1,hi,lt,rt));
}
int l[N+2],r[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<vector<int> >v(n),u(n);
   for(int i=0;i<n;i++)
  {
    v[i].resize(3);
    for(int j=0;j<3;j++)cin>>v[i][j];
    u[i]={v[i][1],v[i][0],v[i][2]};
    l[i]=v[i][0],r[i]=v[i][2];
  }
  int a=0,b=0,ans=-1,lo,hi;build(1,1,N);
  sort(v.begin(),v.end());sort(u.begin(),u.end());
  for(int i=1;i<=N;i++)
  {
    while((a<n)&&(v[a][0]<=i))
    {
      upd(1,1,N,v[a][1],v[a][2],1);
      a++;
    }
    while((b<n)&&(u[b][0]<i))
    {
      upd(1,1,N,u[b][0],u[b][2],-1);
      b++;
    }
    pair<int,int>p=get(1,1,N,1,N);
    if(p.first>ans)ans=p.first,lo=i,hi=p.second;
  }
  cout<<ans<<endl;int cnt=0;
  //cout<<lo<<" "<<hi<<endl;
  for(int i=0;i<n;i++)
  {
    //cout<<l[i]<<" "<<r[i]<<endl;
    if(l[i]<=lo&&r[i]>=hi){cnt++;cout<<i+1<<" ";}
  }
  assert(cnt==ans);
  cout<<endl;
  return 0;
}