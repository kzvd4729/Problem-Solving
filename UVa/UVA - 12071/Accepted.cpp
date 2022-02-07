/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-05 20:13:21                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 30                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12071
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e4;
long arr[N+2],dp[N+2],tc;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;
  while(cin>>n)
  {
    if(n==0)break;
    for(int i=1;i<=n;i++)
      cin>>arr[i];
    sort(arr+1,arr+n+1);
    long ans=0;
    for(int i=2;i<=n;i++)
    {
      if(arr[i]==arr[i-1])dp[i]=dp[i-1];
      else dp[i]=i-1;
      ans+=dp[i];
    }
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}