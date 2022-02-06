/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2019 16:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1109/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],fr[N+N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int xxr=0;long ans=0;
  for(int i=1;i<=n;i++)
  {
    xxr^=aa[i];if(i%2==0)fr[xxr]++;
  }
  ans+=fr[0];xxr=0;
  for(int i=1;i<=n;i++)
  {
    xxr^=aa[i];
    if(i%2==0)
    {
      fr[xxr]--;
      ans+=(fr[xxr]*1LL);
    }
  }
   xxr=0;memset(fr,0,sizeof(fr));
  for(int i=2;i<=n;i++)
  {
    xxr^=aa[i];if(i%2==1)fr[xxr]++;
  }
  ans+=fr[0];xxr=0;
  for(int i=2;i<=n;i++)
  {
    xxr^=aa[i];
    if(i%2==1)
    {
      fr[xxr]--;
      ans+=(fr[xxr]*1LL);
    }
  }
  cout<<ans<<endl;
  return 0;
}