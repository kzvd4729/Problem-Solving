/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/28/2020 20:59                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 187 ms                                          memory_used: 10100 KB                             
*  problem: https://codeforces.com/contest/1374/problem/D
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
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
map<int,int>cnt;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;cnt.clear();
    long ans=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;x%=k;if(x==0)continue;
      int now=cnt[x]++;int rm=k-x;
      ans=max(ans,1LL*now*k+rm+1);
    }
    cout<<ans<<endl;
  }
  return 0;
}