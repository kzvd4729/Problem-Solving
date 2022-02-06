/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2020 18:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 451 ms                                          memory_used: 41400 KB                             
*  problem: https://codeforces.com/contest/612/problem/E
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
int a[N+2],b[N+2],vs[N+2];
vector<int>now;
void dfs(int nd)
{
  now.push_back(nd);vs[nd]=1;
  if(vs[a[nd]]==0)dfs(a[nd]);
}
vector<int>bf[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++)
  {
    if(vs[i])continue;
    now.clear();dfs(i);
     int sz=now.size();
    //for(int j=0;j<sz;j++)cout<<now[j]<<" ";cout<<endl;
    if(sz%2==0)
    {
      if(bf[sz].size()==0)bf[sz]=now;
      else
      {
        b[bf[sz][0]]=a[now[sz-1]];
        for(int j=1;j<sz;j++)
          b[bf[sz][j]]=a[now[j-1]];
        for(int j=0;j<sz;j++)
          b[now[j]]=a[bf[sz][j]];
         bf[sz].clear();
      }
    }
    else
    {
      for(int j=0;j<sz;j++)
        b[now[j]]=a[now[(sz/2+j)%sz]];
    }
  }
  for(int i=1;i<=n;i++)if(bf[i].size()>0)cout<<-1<<endl,exit(0);
  for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
  return 0;
}