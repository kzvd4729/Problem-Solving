/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2020 20:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1353/problem/C
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
const int N=1e6;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;long ans=0,now=8,cnt=1;
    for(int i=3;i<=n;i+=2)
    {
      ans+=1LL*now*cnt;cnt++;now+=8;
    }
    cout<<ans<<"\n";
  }
  return 0;
}