/****************************************************************************************
*  @author: kzvd4729                                         created: May/03/2018 01:12                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 62 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/965/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int print,arr[100005],n,k,slide;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<n;i++)
    cin>>arr[i];
  for(int i=1;i<=k;i++)
    slide+=arr[i];
  print=slide;
  for(int i=k+1;i<n;i++)
  {
    slide+=(arr[i]-arr[i-k]);
    print=min(print,slide);
  }
  cout<<print<<endl;
  return 0;
}