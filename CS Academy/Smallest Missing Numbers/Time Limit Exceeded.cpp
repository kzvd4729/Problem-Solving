/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time: 1096 ms                                         memory_used: 780 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,x;
int arr[100005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  sort(arr+1,arr+n+1);
  arr[n+1]=2e9;
  int now=1,id=1;
  long sum=0;
  while(m)
  {
    if(arr[id]==now)
    {
      while(arr[id]==now)id++;
      now++;
    }
    else
    {
      sum+=(now*1LL);
      now++;
      m--;
    }
  }
  cout<<sum<<endl;
  return 0;
}