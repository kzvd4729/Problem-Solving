/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/05/2018 22:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1040/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int arr[10003];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,a,b,ans=0;cin>>n>>a>>b;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  for(int i=1;i<=(n+1)/2;i++)
  {
    int j=n-i+1;
    if(i==j)
    {
      if(arr[i]==2)ans+=min(a,b);
    }
    else
    {
      if(arr[i]==arr[j])
      {
        if(arr[i]==2)
          ans+=2*min(a,b);
      }
      else
      {
        if(arr[i]!=2&&arr[j]!=2)cout<<-1<<endl,exit(0);
        if(arr[i]==2)
        {
          if(arr[j]==0)ans+=a;
          else ans+=b;
        }
        else if(arr[j]==2)
        {
          if(arr[i]==0)ans+=a;
          else ans+=b;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}