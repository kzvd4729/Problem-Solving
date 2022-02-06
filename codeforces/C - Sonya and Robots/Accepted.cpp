/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2018 23:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/1004/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
long n,arr[N+2],vis[N+2],fr[N+2],cnt,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)
    cin>>arr[i];
   for(long i=n;i>=1;i--)
  {
    fr[arr[i]]++;
    if(fr[arr[i]]==1)cnt++;
  }
  for(long i=1;i<=n;i++)
  {
    fr[arr[i]]--;
    if(fr[arr[i]]==0)cnt--;
    if(vis[arr[i]])continue;
    vis[arr[i]]=1;
    ans+=cnt;
  }
  cout<<ans<<endl;
   return 0;
}