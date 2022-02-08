/****************************************************************************************
*  @author: kzvd4729                                         created: 24-11-2018 20:19:41                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.18 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/LTIME66A/problems/USF
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int vis[N+2],cnt[N+2],pr[N+2];
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
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      pr[j]++;vis[j]=1;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  divisors();
  int t;cin>>t;
  while(t--)
  {
    memset(cnt,0,sizeof(cnt));
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      for(auto xx:vd[x])
        cnt[xx]++;
    }
    long ans=0;
    for(int i=2;i<=N;i++)
      ans=max(ans,(cnt[i]*1LL*pr[i]));
    cout<<ans<<endl;
  }
  return 0;
}