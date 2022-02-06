/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2018 17:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/998/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[102],s,sum;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    sum+=arr[i];
  }
  for(int i=1;i<=n;i++)
  {
    s+=arr[i];
    if(s!=sum&&sum-s!=s)
    {
      cout<<i<<endl;
      for(int j=1;j<=i;j++)
        cout<<j<<" ";
      cout<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}