/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2020 18:02                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1348/problem/E
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
#include<unordered_map>
#define long long long
using namespace std;
const int N=5e2,mod=1e9+7;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  long a=0,b=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i]>>bb[i];a+=aa[i],b+=bb[i];
  }
  long ans=a/k+b/k;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=min(k,aa[i]);j++)
    {
      long ta=a-j,tb=b-(k-j);
      if(ta<0||tb<0||k-j>bb[i])continue;
      ans=max(ans,1+ta/k+tb/k);
    }
  }
  cout<<ans<<endl;
  return 0;
}