/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/07/2018 00:20                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4800 KB                              
*  problem: https://codeforces.com/contest/731/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,arr[N+2],vis[N+2],id,id2,x;
long sum,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  sort(arr+1,arr+n+1);
   for(int i=1;i<=n;i++)
  {
    x=arr[i];
    if(vis[x])continue;
    vis[x]=1;
    sum=0;
    id=i;
    for(int j=x+x;j<=N;j+=x)
    {
      id2=upper_bound(arr+id,arr+n+1,j-1)-arr;
      sum+=((id2-id)*1LL*(j-x)*1LL);
      id=id2;
      vis[j]=1;
    }
    ans=max(ans,sum);
  }
  cout<<ans<<endl;
  return 0;
}