/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2020 16:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/687/problem/B
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
const int N=1e6,R=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=2;i<=k;i++)
  {
    if(k%i)continue;
    int p=1;while(k%i==0)k/=i,p*=i;
    int f=0;
    for(int j=1;j<=n;j++)
    {
      if(aa[j]%p==0)f=1;
    }
    if(!f)cout<<"No\n",exit(0);
  }
  cout<<"Yes\n";
  return 0;
}