/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2020 20:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 34600 KB                             
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
int a[N+2],f;long mx;
pair<long,long>dfs(int nd)
{
  pair<long,long>p={a[nd],0};
  if((int)ad[nd].size()==0)p.second++;
   for(auto x:ad[nd])
  {
    pair<long,long>q=dfs(x);
    p.first+=q.first,p.second+=q.second;
  }
  mx=max(mx,(p.first+p.second-1)/p.second);
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
  dfs(1);cout<<mx<<endl;
  return 0;
}