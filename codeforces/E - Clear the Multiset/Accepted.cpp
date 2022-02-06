/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2020 11:56                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 78 ms                                           memory_used: 98300 KB                             
*  problem: https://codeforces.com/contest/1400/problem/E
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
#define long long long
using namespace std;
const int N=5e3;
int a[N+2],mt[N+2][N+2];
int dfs(int lo,int hi,int sb)
{
  if(lo>hi)return 0;
  int id=mt[lo][hi];
  int now=a[id]-sb;
   return min(hi-lo+1,now+dfs(lo,id-1,sb+now)+dfs(id+1,hi,sb+now));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)
  {
    mt[i][i]=i;
    for(int j=i+1;j<=n;j++)
    {
      if(a[j]<a[mt[i][j-1]])mt[i][j]=j;
      else mt[i][j]=mt[i][j-1];
    }
  }
  cout<<dfs(1,n,0)<<endl;
  return 0;
}