/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2018 14:56                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/934/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e12;
const long N=2e3;
long n,arr[N+2],ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int j=1;j<=n;j++)
  {
    long cnt=0,f=0;
    for(int i=j;i<=n;i++)
    {
      if(arr[i]==1)
      {
        if(f==0)f=1;
        if(f==2)f=3;
        if(f==4)break;
        cnt++;
      }
      else
      {
        if(f==0||f==1)f=2;
        if(f==3)f=4;
        cnt++;
      }
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}