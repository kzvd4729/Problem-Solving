/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/05/2020 21:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1996 ms                                         memory_used: 77200 KB                             
*  problem: https://codeforces.com/contest/1029/problem/D
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
int aa[N+2];
int dg(int x)
{
  int ret=0;
  while(x)
  {
    ret++;x/=10;
  }
  return ret;
}
map<int,int>mp[12];
int pw[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  pw[0]=1;
  for(int i=1;i<=10;i++)pw[i]=(10LL*pw[i-1])%k;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
    mp[dg(aa[i])][aa[i]%k]++;
  }
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    mp[dg(aa[i])][aa[i]%k]--;
    for(int j=1;j<=10;j++)
      ans+=mp[j][(k-(1LL*aa[i]*pw[j])%k+k)%k];
    mp[dg(aa[i])][aa[i]%k]++;
  }
  cout<<ans<<endl;
  return 0;
}