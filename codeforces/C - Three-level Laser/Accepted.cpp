/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2018 19:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/957/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k,arr[100005],f;
double ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<=n;i++)
  {
    int lo=i+2,hi=n,md,id=-1;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(arr[md]-arr[i]<=k)lo=md;
      else hi=md;
    }
    for(int j=hi;j>=lo;j--)
    {
      if(arr[j]-arr[i]<=k)
      {
        id=j;
        break;
      }
    }
    if(id==-1)continue;
    f=1;
    ans=max(ans,((arr[id]-arr[i+1])*1.00)/((arr[id]-arr[i])*1.00));
  }
  if(!f)cout<<-1<<endl;
  else cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}