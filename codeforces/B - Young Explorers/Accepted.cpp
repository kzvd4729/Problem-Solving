/****************************************************************************************
*  @author: * kzvd4729                                       created: May/16/2020 17:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1355/problem/B
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
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)fr[i]=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;fr[x]++;
    }
    for(int i=1;i<=n;i++)fr[i]+=fr[i-1];
    int ans=0,us=0;
    for(int i=1;i<=n;i++)
    {
      int rm=fr[i]-us;
      if(rm>=i)
      {
        ans++;us+=i;i--;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}