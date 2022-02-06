/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2021 22:11                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 779 ms                                          memory_used: 117300 KB                            
*  problem: https://codeforces.com/contest/1519/problem/E
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int a[N+2],b[N+2],c[N+2],d[N+2];
 pair<long,long>xPlusOne(int i)
{
  long up1=a[i]+b[i],dw1=b[i],up2=c[i],dw2=d[i];
   long up=up2*dw1,dw=up1*dw2;
   long gc=__gcd(up,dw);
  up/=gc,dw/=gc;
   return {up,dw};
}
pair<long,long>yPlusOne(int i)
{
  long up1=a[i],dw1=b[i],up2=c[i]+d[i],dw2=d[i];
   long up=up2*dw1,dw=up1*dw2;
   long gc=__gcd(up,dw);
  up/=gc,dw/=gc;
   return {up,dw};
}
 int ent[N+2],tim;
vector<pair<int,int> >ad[N+2];
int cnt[N+2];
 void dfs(int nd)
{
  if(ent[nd])return ;
  ent[nd]=++tim;
   for(auto x:ad[nd])dfs(x.first);
}
int vs[N+2];
vector<int>com[N+2];
void color(int nd)
{
  if(vs[nd])return ;
  vs[nd]=1;
   for(auto x:ad[nd])
  {
    color(x.first);
     if(ent[x.first]>ent[nd])
    {
      if(cnt[x.first]%2)cnt[x.first]++,com[x.first].push_back(x.second);
      else cnt[nd]++,com[nd].push_back(x.second);
    }
  }
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
    vector<pair<long,long> >v;
  for(int i=1;i<=n;i++)
  {
    v.push_back(xPlusOne(i));
    v.push_back(yPlusOne(i));
  }
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<pair<long,long>,int> mp;
   int sz=v.size();
  for(int i=0;i<sz;i++)mp[v[i]]=i+1;
   for(int i=1;i<=n;i++)
  {
    int u=mp[xPlusOne(i)];
    int v=mp[yPlusOne(i)];
     ad[u].push_back({v,i});ad[v].push_back({u,i});
     //cout<<u<<" "<<v<<endl;
  }
   for(int i=1;i<=sz;i++)
  {
    dfs(i);color(i);
  }
   int ans=0;
  for(int i=1;i<=sz;i++)ans+=cnt[i]/2;
   cout<<ans<<'\n';
  for(int i=1;i<=sz;i++)
  {
    for(int j=1;j<(int)com[i].size();j+=2)
    {
      cout<<com[i][j-1]<<" "<<com[i][j]<<'\n';
    }
  }
    return 0;
}