/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/19/2021 22:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 23700 KB                             
*  problem: https://codeforces.com/contest/1474/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9,mod=1e9+7;
long a[N+2],vl[N+2],mn[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     long od=a[1],ev=0;
    for(int i=2;i<=n;i++)
    {
      if(i%2==0)
      {
        ev+=a[i];
        vl[i]=ev-od;
      }
      else
      {
        od+=a[i];
        vl[i]=od-ev;
      }
    }
    int f=1;
    for(int i=2;i<=n;i++)if(vl[i]<0)f=0;
    if(f&&vl[n]==0)
    {
      cout<<"YES\n";continue;
    }
    mn[n]=vl[n],mn[n-1]=vl[n-1];
    for(int i=n-2;i>=1;i--)mn[i]=min(mn[i+2],vl[i]);
     //for(int i=1;i<=n;i++)cout<<vl[i]<<" ";cout<<endl;
     f=0;
    for(int i=2;i<=n;i++)
    {
      if(vl[i-2]<0)break;
      if(i>2&&vl[i-1]-a[i-1]+a[i]<0)continue;
      if(mn[i]+2*a[i-1]-2*a[i]<0)continue;
      if(i+1<=n&&mn[i+1]+2*a[i]-2*a[i-1]<0)continue;
       if(i%2==n%2)
      {
        if(vl[n]+2*a[i-1]-2*a[i]==0){f=1;break;}
      }
      else
      {
        if(vl[n]+2*a[i]-2*a[i-1]==0){f=1;break;}
      }
    }
    if(f)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}