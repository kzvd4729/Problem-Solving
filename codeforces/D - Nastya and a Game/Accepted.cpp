/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/12/2019 19:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/992/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long unsigned long long
using namespace std;
const int N=1e6;
long k,aa[N+2],nxt[N+2];
const long mx=4000000000000000000;
long mul(long a,long b)
{
 long c=mx/a;
 if(b>c)return 0;
 return a*b;
}
bool isOk(long ml,long lt,long rt)
{
 if(ml%k)return 0;
 long md=ml/k;
 if(md>=lt&&md<=rt)return 1;
 return 0;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n>>k;
 for(int i=1;i<=n;i++)cin>>aa[i];
 nxt[n+1]=n+1;
 for(int i=n;i>=1;i--)
 {
  if(aa[i]==1)nxt[i]=nxt[i+1];
  else nxt[i]=i;
 }
 /*for(int i=1;i<=n;i++)
  cout<<nxt[i]<<" ";
 cout<<endl;*/
 long ans=0;
 for(int i=1;i<=n;i++)
 {
  long sm=0,ml=1;
  for(int j=i;j<=n;j++)
  {
   int f=0;
   if(aa[j]==1)
   {
    f=isOk(ml,sm+1,sm+nxt[j]-j);
    sm+=nxt[j]-j;j=nxt[j]-1;
   }
   else
   {
    ml=mul(ml,aa[j]);
    if(ml<=0)break;sm+=aa[j];
    f=isOk(ml,sm,sm);
   }
   ans+=f;
   //if(f)cout<<i<<" "<<j<<" "<<ml<<" "<<sm<<endl;
  }
 }
 cout<<ans<<endl;
 return 0;
}