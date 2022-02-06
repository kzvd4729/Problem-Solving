/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2020 19:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/1327/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,mod=998244353;
long pw[N+2],ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(10LL*pw[i-1])%mod;
   ans[1]=10;
  for(int n=2;n<=N;n++)
    ans[n]=(pw[n-1]*9+pw[n-2]*81*(n-2)+pw[n-1]*9)%mod;
  int n;cin>>n;
  for(int i=n;i>=1;i--)
    cout<<ans[i]<<" ";cout<<endl;
    return 0;
}