/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2020 14:43                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/229/problem/D
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
int n,a[N+2],b[N+2];
int solve(int id,int sm)
{
  if(b[n]-b[id]<sm)return N;
  int ret=0;
  for(int i=id+1;i<=n;i++)
  {
    if(b[i]-b[id]>=sm)
    {
      if(b[n]-b[i]<b[i]-b[id])
      {
        return ret+n-id-1;
      }
      else
      {
        ret+=i-id-1;
        sm=b[i]-b[id];id=i;
      }
    }
  }
  return N;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]+a[i];
   int ans=n-1;
    for(int i=1;i<n;i++)
  {
    ans=min(ans,i-1+solve(i,b[i]));
    //cout<<i<<" "<<i-1+solve(i,b[i])<<endl;
  }
  cout<<ans<<endl;
   return 0;
}