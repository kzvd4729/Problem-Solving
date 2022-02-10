/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 280 ms                                          memory_used: 668 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define log long long
using namespace std;
const long inf=1e12;
long n,arr[150003],now,dis[50004],mx,mxx=inf,ans,j,kk;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(long i=1;i<=n;i++)cin>>arr[i],arr[n+i]=arr[i],arr[n+n+i]=arr[i];
  for(long i=1;i<=n;i++)
  {
    j=n+i;
    for(long k=1;k<=n;k++)dis[k]=inf;
    now=0;
    dis[i]=0;
    for(long k=j+1;k<=3*n;k++)
    {
      now+=arr[k-1];
      kk=k;
      if(kk>n)kk-=n;
      if(kk>n)kk-=n;
      dis[kk]=min(dis[kk],now);
    }
    now=0;
    for(long k=j-1;k>=1;k--)
    {
      now+=arr[k];
      kk=k;
      if(kk>n)kk-=n;
      if(kk>n)kk-=n;
      dis[kk]=min(dis[kk],now);
    }
    mx=0;
    for(long k=1;k<=n;k++)mx=max(mx,dis[k]);
    if(mx<mxx)
    {
      mxx=mx;
      ans=i;
    }
//    for(long k=1;k<=n;k++)cout<<dis[k]<<" ";
//    cout<<endl;
  }
  cout<<ans<<endl;
  return 0;
}