/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2018 13:59                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/996/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[102],ans;
int _find(int id,int x)
{
  for(int i=id;i<=n;i++)
    if(arr[i]==x)return i;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  n*=2;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  for(int i=1;i<=n;i+=2)
  {
    int id=_find(i+1,arr[i]);
    ans+=id-i-1;
    for(int j=id;j>i-1;j--)
      swap(arr[j],arr[j-1]);
  }
  cout<<ans<<endl;
  return 0;
}