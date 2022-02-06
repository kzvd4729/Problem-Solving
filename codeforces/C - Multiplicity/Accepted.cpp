/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/22/2018 22:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1450 ms                                         memory_used: 104800 KB                            
*  problem: https://codeforces.com/contest/1061/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
long pr[N+2];
vector<int>vd[N+2];
void divisors(void)
{
  for(int i=2;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
    {
      vd[j].push_back(i);
    }
  }
  for(int i=2;i<=N;i++)
    sort(vd[i].begin(),vd[i].end(),greater<int>());
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  divisors();
  int n;cin>>n;int mx=2;int tmp;cin>>tmp;pr[1]++;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;
    for(auto xx:vd[x])
    {
      if(xx>mx)continue;
      pr[xx]=(pr[xx]+pr[xx-1])%mod;
    }
    pr[1]++;
    if(x%mx==0)mx++;
  }
  long ans=0;
  for(int i=1;i<=mx;i++)
    ans=(ans+pr[i])%mod;
  cout<<ans<<endl;
  return 0;
}