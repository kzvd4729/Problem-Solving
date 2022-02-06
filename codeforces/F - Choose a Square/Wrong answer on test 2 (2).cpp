/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2020 23:30                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 52800 KB                             
*  problem: https://codeforces.com/contest/1221/problem/F
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
const int N=5e5;
const long inf=1e18;
int a[N+2],b[N+2],c[N+2];
map<int,vector<pair<int,long>>>mp;
long lz[4*N+8];pair<long,int>mx[4*N+8];
void tooLazy(int nd,int lo,int hi)
{
  mx[nd].first+=lz[nd];
  if(lo!=hi)lz[nd*2]+=lz[nd],lz[nd*2+1]+=lz[nd];
  lz[nd]=0;
}
vector<pair<int,long>>v;
void build(int nd,int lo,int hi)
{
  if(lo==hi){mx[nd]={v[lo].second,v[lo].first};return ;}
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
  mx[nd]=max(mx[nd*2],mx[nd*2+1]);
}
void upd(int nd,int lo,int hi,int lt,int rt,long ad)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[nd]+=ad;tooLazy(nd,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  upd(nd*2,lo,md,lt,rt,ad);upd(nd*2+1,md+1,hi,lt,rt,ad);
  mx[nd]=max(mx[nd*2],mx[nd*2+1]);
}
pair<long,int>getMax(int nd,int lo,int hi,int lt,int rt)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return {-inf,-inf};
  if(lo>=lt&&hi<=rt)return mx[nd];
  int md=(lo+hi)/2;
  return max(getMax(nd*2,lo,md,lt,rt),getMax(nd*2+1,md+1,hi,lt,rt));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
   map<int,long>cs;
  for(int i=1;i<=n;i++)
  {
    if(a[i]>b[i])swap(a[i],b[i]);
    cs[b[i]]+=c[i];
    mp[a[i]].push_back({b[i],c[i]});
  }
  for(auto x:cs)v.push_back({x.first,x.second});
   int sz=v.size();
   for(int i=1;i<sz;i++)v[i].second+=v[i-1].second;
  //for(int i=0;i<sz;i++)cout<<v[i].first<<" "<<v[i].second<<endl;
    //cout<<endl;
  for(int i=1;i<sz;i++)v[i].second+=v[i-1].first-v[i].first;
  build(1,0,sz-1);pair<long,int>ans;
  ans={0,0};int bg;
  for(auto x:mp)
  {
    pair<long,int>p=getMax(1,0,sz-1,0,sz-1);
    if(p>ans)ans=p,bg=x.first;
    vector<pair<int,long>>dl=mp[x.first];
    for(auto d:dl)
    {
      //cout<<x.first<<" "<<d.first<<" "<<d.second<<endl;
      int id=lower_bound(v.begin(),v.end(),make_pair(d.first,-inf))-v.begin();
      upd(1,0,sz-1,id,sz-1,-d.second);
    }
  }
  //cout<<ans.first<<" "<<ans.second<<endl;
  int ll=1e9;
  if(ans.first==0)cout<<0<<" "<<ll+1<<" "<<ll+1<<" "<<ll+2<<" "<<ll+2<<endl;
  else cout<<ans.first<<" "<<bg<<" "<<bg<<" "<<ans.second<<" "<<ans.second<<endl;
  return 0;
}