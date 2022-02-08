/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-25 18:12:20                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 160 ms                                          memory_used: 2048 KB                              
*  problem: https://atcoder.jp/contests/arc093/tasks/arc093_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long sum,arr[100005],n,summ;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  arr[0]=0;
  arr[n+1]=0;
  for(int i=0;i<=n;i++)sum+=abs(arr[i]-arr[i+1]);
  for(int i=1;i<=n;i++)
  {
    summ=sum;
    summ-=abs(arr[i]-arr[i+1]);
    summ-=abs(arr[i]-arr[i-1]);
    summ+=abs(arr[i-1]-arr[i+1]);
    cout<<summ<<endl;
  }
  return 0;
}