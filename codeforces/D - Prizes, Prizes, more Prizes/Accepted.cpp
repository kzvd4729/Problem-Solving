/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2018 14:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/208/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int n,arr[N+2],pr[N+2];
long cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  for(int j=1;j<=5;j++)
    cin>>pr[j];
   long sum=0;
  for(int i=1;i<=n;i++)
  {
    sum+=(arr[i])*1LL;
    for(int j=5;j>=1;j--)
    {
      if(pr[j]<=sum)
      {
        int tmp=sum/pr[j];
        cnt[j]+=tmp*1LL;
        sum-=(tmp*pr[j]);
      }
    }
  }
  for(int i=1;i<=5;i++)
    cout<<cnt[i]<<" ";
  cout<<endl;
  cout<<sum<<endl;
  return 0;
}