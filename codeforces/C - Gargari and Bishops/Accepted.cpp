/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2020 22:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1153 ms                                         memory_used: 31400 KB                             
*  problem: https://codeforces.com/contest/463/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e3,inf=1e9;
long a[N+2][N+2],pl[N+N+2],mn[N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=n;j++)
    {
      cin>>a[i][j];
      pl[i+j]+=a[i][j];mn[i-j+N]+=a[i][j];
    }
  }
  // for(long i=0;i<=N+N;i++)
  //   if(pl[i])cout<<i<<" "<<pl[i]<<endl;
  // cout<<endl;
  // for(long i=0;i<=N+N;i++)
  //   if(mn[i])cout<<i-N<<" "<<mn[i]<<endl;
  long bl=-1,wh=-1,p,q,r,s;
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=n;j++)
    {
      if((i+j)%2)
      {
        if(pl[i+j]+mn[i-j+N]-a[i][j]>bl)
          bl=pl[i+j]+mn[i-j+N]-a[i][j],p=i,q=j;
      }
      else
      {
        if(pl[i+j]+mn[i-j+N]-a[i][j]>wh)
          wh=pl[i+j]+mn[i-j+N]-a[i][j],r=i,s=j;
      }
    }
  }
  cout<<bl+wh<<endl;
  cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
  return 0;
}