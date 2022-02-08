/****************************************************************************************
*  @author: kzvd4729                                         created: 08-10-2019 11:30:55                      
*  solution_verdict: Time Limit Exceeded                     language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/OCT19A/problems/MSV
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int mx[N+2];
vector<int>vd[N+2];
void divisors(void)
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
      vd[j].push_back(i);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  divisors();int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int ans=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      ans=max(ans,mx[x]);
      for(auto a:vd[x])mx[a]++;
    }
    cout<<ans<<endl;memset(mx,0,sizeof(mx));
  }
  return 0;
}