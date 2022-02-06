/****************************************************************************************
*  @author: kzvd4729                                         created: May/29/2020 11:47                        
*  solution_verdict: Wrong answer on test 65                 language: GNU C++14                               
*  run_time: 421 ms                                          memory_used: 161500 KB                            
*  problem: https://codeforces.com/contest/712/problem/D
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
const long N=1e6,mod=1e9+7,C=1e5;
long dp[100+2][C+C+2],qm[C+C+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long a,b,k,t;cin>>a>>b>>k>>t;
   dp[0][C]=1;for(long i=C;i<=C+C;i++)qm[i]=1;
  auto ret=[&](long i,long j)
  {
    return (qm[min(j,C+C)]-qm[max(0LL,i-1)]+mod)%mod;
  };
  for(long i=1;i<=t;i++)
  {
    for(long j=0;j<=C+C;j++)
      dp[i][j]=ret(j-k,j+k);
    qm[0]=dp[i][0];
    for(long j=1;j<=C+C;j++)
      qm[j]=(qm[j-1]+dp[i][j])%mod;
  }
  long ans=0;
  for(long i=0;i<=C+C;i++)
  {
    long aa=a+i-C;
    if(aa-b-1+C>=0)ans+=1LL*dp[t][i]*qm[aa-b-1+C];ans%=mod;
  }
  cout<<(ans+mod)%mod<<endl;
  return 0;
}