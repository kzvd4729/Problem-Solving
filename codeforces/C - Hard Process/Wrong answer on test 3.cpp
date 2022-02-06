/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2018 20:07                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 4900 KB                              
*  problem: https://codeforces.com/contest/660/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k,arr[300003];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>arr[i],arr[i]+=arr[i-1];
  int here,ans=0,id;
  for(int i=1;i<=n;i++)
  {
    int lo=i,hi=n,md;
     while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if((md-i+1)-(arr[md]-arr[i-1])>k)hi=md;
      else lo=md;
    }
     for(int j=lo;j<=hi;j++)
    {
      if((j-i+1)-(arr[j]-arr[i-1])<=k)
        here=j-i+1;
    }
    if(here>ans)
    {
      ans=here;
      id=i;
    }
  }
  cout<<ans<<endl;
  for(int i=1;i<=n;i++)
  {
    if(i>=id&&i<id+ans)cout<<1<<" ";
    else cout<<arr[i]-arr[i-1]<<" ";
  }
  cout<<endl;
  return 0;
}