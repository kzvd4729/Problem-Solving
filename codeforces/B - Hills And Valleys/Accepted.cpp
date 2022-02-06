/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/08/2021 20:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1467/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9+1;
int n,a[N+2];
bool ck(int i)
{
  if(i<=1||i>=n)return 0;
  if(a[i]<a[i-1]&&a[i]<a[i+1])return 1;
  if(a[i]>a[i-1]&&a[i]>a[i+1])return 1;
  return 0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     int cnt=0;
    for(int i=1;i<=n;i++)cnt+=ck(i);
     int ans=cnt;
    for(int i=1;i<=n;i++)
    {
      int now=cnt-ck(i-1)-ck(i)-ck(i+1);
      int rm=a[i];
       a[i]=-inf;
      ans=min(ans,now+ck(i-1)+ck(i)+ck(i+1));
       a[i]=inf;
      ans=min(ans,now+ck(i-1)+ck(i)+ck(i+1));
       a[i]=a[i-1];
      ans=min(ans,now+ck(i-1)+ck(i)+ck(i+1));
       a[i]=a[i+1];
      ans=min(ans,now+ck(i-1)+ck(i)+ck(i+1));
       a[i]=(a[i-1]+a[i+1])/2;
      ans=min(ans,now+ck(i-1)+ck(i)+ck(i+1));
       a[i]=rm;
    }
    cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}