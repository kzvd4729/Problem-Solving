/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-05-03 12:16:57                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 17 ms                                           memory_used: 2304 KB                              
*  problem: https://atcoder.jp/contests/agc006/tasks/agc006_b
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  if(k==1||k==n+n-1)cout<<"No\n",exit(0);
  cout<<"Yes\n";
   aa[n]=k;aa[n-1]=k-1;aa[n+1]=k+1;
  int cnt=0;
  for(int i=1;i<=n+n-1;i++)
  {
    if(aa[i])continue;cnt++;
    if(cnt>=k-1&&cnt<=k+1){i--;continue;}
    aa[i]=cnt;
  }
  for(int i=1;i<=n+n-1;i++)cout<<aa[i]<<" ";cout<<endl;
  return 0;
}