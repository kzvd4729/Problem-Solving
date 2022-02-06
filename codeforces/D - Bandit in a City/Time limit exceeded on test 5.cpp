/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2020 20:04                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 66900 KB                             
*  problem: https://codeforces.com/contest/1436/problem/D
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
const long N=1e6;
long tim,ent[N+2],ext[N+2],hg[N+2];
vector<long>ad[N+2];
void dfs(long nd,long h)
{
  ent[nd]=++tim;hg[nd]=h;
  for(auto x:ad[nd])dfs(x,h+1);
  ext[nd]=tim;
}
long a[N+2],b[N+2],c[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=2;i<=n;i++)
  {
    long x;cin>>x;ad[x].push_back(i);
  }
  dfs(1,0);
  for(long i=1;i<=n;i++)cin>>a[i];
  vector<long>v;for(long i=1;i<=n;i++)v.push_back(i);
  sort(v.begin(),v.end(),[&](long a,long b){
    return hg[a]>hg[b];
  });
  long lo=0,hi=1e16+1,md;
  while(lo<hi)
  {
    long md=(lo+hi)/2;set<long>st;
    for(long i=1;i<=n;i++)if((long)ad[i].size()==0)st.insert(ent[i]);
    for(long i=1;i<=n;i++)b[i]=0;
     long f=0;
    for(auto x:v)
    {
      long l=ent[x]-1,now=a[x];
      while(true)
      {
        auto it=st.upper_bound(l);
        if(it==st.end()||*it>ext[x])break;
         l=*it;
        if(md-b[l]<=now)
        {
          now-=(md-b[l]);b[l]=md;
          st.erase(l);
        }
        else
        {
          b[l]+=now;now=0;break;
        }
      }
      if(now){f=1;break;}
    }
    if(f==0)hi=md;else lo=md+1;
  }
  cout<<lo<<endl;
  return 0;
}