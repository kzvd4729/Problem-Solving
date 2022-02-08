/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-11-09 22:14:40                      
*  solution_verdict: TLE                                     language: C++ (GCC 9.2.1)                         
*  run_time: 2205 ms                                         memory_used: 3652 KB                              
*  problem: https://atcoder.jp/contests/abc182/tasks/abc182_f
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
long a[N+2];
vector<long>v,m;
long dfs(int i,int c)
{
  if(i==0)return 1;
  long ret=0;
  ret+=dfs(i-1,(v[i]+c)/m[i]);
  if(v[i]+c<m[i]&&v[i]+c>0)ret+=dfs(i-1,1);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,x;cin>>n>>x;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=n;i>=1;i--)
  {
    v.push_back(x/a[i]);
    x%=a[i];
  }
  m.push_back(0);
  for(int i=n-1;i>=1;i--)m.push_back(a[i+1]/a[i]);
  //for(int i=0;i<m.size();i++)cout<<m[i]<<" ";cout<<endl;
  //for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
  cout<<dfs((int)v.size()-1,0)<<endl;
  return 0;
}