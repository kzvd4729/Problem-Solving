/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2020 20:15                        
*  solution_verdict: Time limit exceeded on test 4           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 35200 KB                             
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
const int N=1e6;
int tim,ent[N+2],ext[N+2],hg[N+2];
vector<int>ad[N+2];
void dfs(int nd,int h)
{
  ent[nd]=++tim;hg[nd]=h;
  for(auto x:ad[nd])dfs(x,h+1);
  ext[nd]=tim;
}
int a[N+2];long b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;ad[x].push_back(i);
  }
  dfs(1,0);
  for(int i=1;i<=n;i++)cin>>a[i];
  vector<int>v;for(int i=1;i<=n;i++)if((int)ad[i].size())v.push_back(i);
  sort(v.begin(),v.end(),[&](int a,int b){
    return hg[a]>hg[b];
  });
  long lo=0,hi=2e14+1,md;
  while(lo<hi)
  {
    int md=(lo+hi)/2;set<int>st;
    for(int i=1;i<=n;i++)
    {
      if((int)ad[i].size()==0)st.insert(ent[i]),b[i]=a[i];
      else b[i]=0;
    }
    int f=0;
    for(auto x:v)
    {
      int l=ent[x]-1,now=a[x];
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