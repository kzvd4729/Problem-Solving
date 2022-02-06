/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/04/2018 16:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1060/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int lt[N+2],rt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>lt[i]>>rt[i];
  sort(lt+1,lt+n+1);sort(rt+1,rt+n+1);long ans=n;
  for(int i=1;i<=n;i++)ans+=max(lt[i],rt[i])*1LL;
  cout<<ans<<endl;
  return 0;
}