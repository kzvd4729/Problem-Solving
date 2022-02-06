/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/04/2020 22:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1422/problem/B
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
const int N=1e2;
int a[N+2][N+2];
long cal(vector<int>v)
{
  if(v.size()==1)return 0;
   long mn=1e18;
  for(int i=0;i<v.size();i++)
  {
    long ad=0;
    for(int j=0;j<v.size();j++)
      ad+=abs(v[i]-v[j]);
    mn=min(mn,ad);
  }
  return mn;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;long ans=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    for(int i=1;i<=(n+1)/2;i++)
    {
      for(int j=1;j<=(m+1)/2;j++)
      {
        vector<int>v;v.push_back(a[i][j]);
        if(n-i+1>i)v.push_back(a[n-i+1][j]);
        if(m-j+1>j)v.push_back(a[i][m-j+1]);
        if(n-i+1>i&&m-j+1>j)v.push_back(a[n-i+1][m-j+1]);
         ans+=cal(v);
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}