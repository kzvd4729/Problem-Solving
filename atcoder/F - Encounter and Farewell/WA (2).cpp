/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-03 19:18:20                      
*  solution_verdict: WA                                      language: C++ (GCC 9.2.1)                         
*  run_time: 437 ms                                          memory_used: 8536 KB                              
*  problem: https://atcoder.jp/contests/zone2021/tasks/zone2021_f
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
 int vs[N+2],par[N+2];
 int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
   for(int i=0;i<m;i++)
  {
    int x;cin>>x;vs[x]=1;
  }
   vector<int>v;
  for(int i=0;i<n;i++)if(vs[i]==0)v.push_back(i);
   //for(auto x:v)cout<<x<<" ";cout<<endl;
  for(int i=0;i<n;i++)par[i]=i;
   vector<pair<int,int> >ans;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<min((int)v.size(),30);j++)
    {
      int a=i,b=(i^v[j]);
       int p1=get(a),p2=get(b);
       if(p1==p2)continue;
      ans.push_back({a,b});par[p1]=p2;
    }
  }
   if((int)ans.size()!=n-1)cout<<-1<<endl,exit(0);
   for(auto x:ans)cout<<x.first<<" "<<x.second<<endl;
     return 0;
}