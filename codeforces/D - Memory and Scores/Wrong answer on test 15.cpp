/****************************************************************************************
*  @author: kzvd4729                                         created: May/29/2020 11:42                        
*  solution_verdict: Wrong answer on test 15                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 80600 KB                             
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
const int N=1e6,mod=1e9+7,C=1e5;
int dp[100+2][C+C+2],qm[C+C+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,k,t;cin>>a>>b>>k>>t;
   dp[0][C]=1;for(int i=C;i<=C+C;i++)qm[i]=1;
  auto ret=[&](int i,int j)
  {
    return qm[min(j,C+C)]-qm[max(0,i-1)];
  };
  for(int i=1;i<=t;i++)
  {
    for(int j=0;j<=C+C;j++)
      dp[i][j]=ret(j-k,j+k);
    qm[0]=dp[i][0];
    for(int j=1;j<=C+C;j++)
      qm[j]=(qm[j-1]+dp[i][j])%mod;
  }
  long ans=0;
  for(int i=0;i<=C+C;i++)
  {
    int aa=a+i-C;
    ans+=1LL*dp[t][i]*qm[aa-b-1+C];ans%=mod;
  }
  cout<<(ans+mod)%mod<<endl;
  return 0;
}