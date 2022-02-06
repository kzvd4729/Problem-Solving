/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2020 19:07                        
*  solution_verdict: Wrong answer on test 43                 language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 5500 KB                              
*  problem: https://codeforces.com/contest/1328/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],bf[N+2],af[N+2];long pr[N+2],sf[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1);
   for(int i=1;i<=n;i++)pr[i]=pr[i-1]+aa[i];
  for(int i=n;i>=1;i--)sf[i]=sf[i+1]+aa[i];
   bf[1]=0;
  for(int i=2;i<=n;i++)
  {
    if(aa[i]==aa[i-1])bf[i]=bf[i-1];
    else bf[i]=i-1;
  }
  af[n]=n+1;
  for(int i=n;i>=1;i--)
  {
    if(aa[i]==aa[i+1])af[i]=af[i+1];
    else af[i]=i+1;
  }
  //for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<endl;
  long ans=1e18;
  for(int i=1;i<=n;i++)
  {
    int b=bf[i],a=af[i];
    int now=n-(b+n-a+1);
    if(now>=k)cout<<0<<endl,exit(0);
     long cs1=1LL*aa[b]*b-pr[b];
    long cs2=sf[a]-1LL*aa[a]*(n-a+1);
     //cout<<cs1<<" "<<cs2<<endl;
     if(b+now>=k)ans=min(ans,cs1+1LL*(k-now)*(aa[i]-aa[b]));
    if(n-a+1+now>=k)ans=min(ans,cs2+1LL*(k-now)*(aa[a]-aa[i]));
     long tt=cs1+cs2;
    if(aa[i]-aa[b]<aa[a]-aa[i])
    {
      int tk=min(k-now,b);
      now+=tk;tt+=1LL*tk*(aa[i]-aa[b]);
       tk=k-now;
      tt+=1LL*tk*(aa[a]-aa[i]);
       ans=min(ans,tt);
    }
    else
    {
      int tk=min(k-now,(n-a+1));
      now+=tk;tt+=1LL*tk*(aa[a]-aa[i]);
       tk=k-now;
      tt+=1LL*tk*(aa[i]-aa[b]);
       ans=min(ans,tt);
    }
  }
  cout<<ans<<endl;
  return 0;
}