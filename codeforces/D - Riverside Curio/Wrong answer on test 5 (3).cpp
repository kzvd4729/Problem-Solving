/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2018 18:26                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4300 KB                              
*  problem: https://codeforces.com/contest/957/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[100005],ans,mx,id,tmp[100005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    if(arr[i]>mx)
    {
      mx=arr[i];
      id=i;
    }
  }
  mx++;
  for(int i=id;i<=n;i++)tmp[i]=mx;
  for(int i=id-1;i>=1;i--)
  {
    mx--;
    mx=max(mx,arr[i]+1);
    tmp[i]=mx;
  }
  for(int i=1;i<=n;i++)ans+=tmp[i]-arr[i]-1;
  cout<<ans<<endl;
  return 0;
}