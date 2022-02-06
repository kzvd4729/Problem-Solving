/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2020 20:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 732 ms                                          memory_used: 37700 KB                             
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
vector<int>ad[N+2];
int a[N+2],f;
pair<long,long>dfs(int nd,long md)
{
  pair<long,long>p={a[nd],0};
  if((int)ad[nd].size()==0)p.second++;

  for(auto x:ad[nd])
  {
    pair<long,long>q=dfs(x,md);
    p.first+=q.first,p.second+=q.second;
  }
  //cout<<md<<" "<<p.first<<" "<<p.second*md<<endl;
  if((p.first+p.second-1)/p.second>md)f=1;
  //if(p.first>p.second*md)f=1;
  return p;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;ad[x].push_back(i);
  }
  for(int i=1;i<=n;i++)cin>>a[i];
  long lo=0,hi=1e15+1,md;
  while(lo<hi)
  {
    md=(lo+hi)/2;f=0;dfs(1,md);
    //cout<<md<<" "<<f<<endl;
    if(f==0)hi=md;else lo=md+1;
  }
  cout<<lo<<endl;
  return 0;
}