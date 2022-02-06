/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2020 14:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1456/problem/B
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
const int N=1e5;
int n,a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  a[0]=0;a[n+1]=2e9+2;
  for(int i=1;i<n;i++)
  {
    int x=(a[i]^a[i+1]);
    if((x<a[i-1])||(x>a[i+2]))cout<<1<<endl,exit(0);
  }
  for(int i=1;i<=n;i++)b[i]=(b[i-1]^a[i]);
  int ans=N;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      for(int k=i;k<j;k++)
      {
        if((b[k]^b[i-1])>(b[j]^b[k]))
          ans=min(ans,j-i-1);
      }
    }
  }
  if(ans==N)ans=-1;cout<<ans<<endl;
  return 0;
}