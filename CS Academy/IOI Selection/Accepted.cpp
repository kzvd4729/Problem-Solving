/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 12 ms                                           memory_used: 684 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int arr[20],ans,mn;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i=1;i<=16;i++)
    cin>>arr[i];
  mn=arr[4];
  for(int i=1;i<=16;i++)
    if(arr[i]+300>mn)ans++;
  cout<<ans<<endl;
  return 0;
}