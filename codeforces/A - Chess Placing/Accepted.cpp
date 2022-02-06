/****************************************************************************************
*  @author: kzvd4729                                         created: May/21/2018 21:09                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/985/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,x,arr[102],b,w,now;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n/2;i++)
    cin>>arr[i];
  sort(arr+1,arr+n/2+1);
  now=1;
  for(int i=1;i<=n/2;i++)
  {
    b+=abs(arr[i]-now);
    now+=2;
  }
  now=2;
  for(int i=1;i<=n/2;i++)
  {
    w+=abs(arr[i]-now);
    now+=2;
  }
  cout<<min(b,w)<<endl;
  return 0;
}