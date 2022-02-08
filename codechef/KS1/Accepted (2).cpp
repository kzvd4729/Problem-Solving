/****************************************************************************************
*  @author: kzvd4729                                         created: 03-08-2019 16:19:49                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.09 sec                                        memory_used: 75.9M                                
*  problem: https://www.codechef.com/AUG19A/problems/KS1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int aa[N+N+2],cnt[N+N+2];
long dis[N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    memset(cnt,0,sizeof(cnt));
    memset(dis,0,sizeof(dis));
    int xxr=0;
    for(int i=1;i<=n;i++)
    {
      xxr^=aa[i],cnt[xxr]++;
      dis[xxr]+=i;
    }
    xxr=0;long ans=0;
    for(int i=1;i<=n;i++)
    {
      ans+=dis[xxr]-1LL*i*cnt[xxr];
      xxr^=aa[i],cnt[xxr]--,dis[xxr]-=i;
    }
    cout<<ans<<endl;
  }
  return 0;
}