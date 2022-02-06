/****************************************************************************************
*  @author: kzvd4729                                         created: May/22/2018 13:22                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/985/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int n,k,d,arr[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k>>d;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  sort(arr+1,arr+n+1);
 //  for(int i=1;i<=n;i++)
//    cout<<arr[i]<<" ";
//  cout<<endl;
  int i;
  for(i=1;i<=n;i++)
  {
    if(arr[i]-arr[1]>d)break;
    dp[i]=dp[i-1];
    if(arr[i]-arr[1]<=d&&i>=k)
      dp[i]++;
  }
  for( ;i<=n;i++)
  {
    dp[i]=dp[i-1];
    int lt=lower_bound(arr+1,arr+i,arr[i]-d)-arr;
    int rt=i-k+1;
    lt--;
    rt--;
    if(lt>rt)continue;
    if(dp[rt]-dp[lt-1]>0)
      dp[i]++;
  }
  if(dp[n])cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}