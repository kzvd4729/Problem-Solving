/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2018 00:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/846/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e3;
long aa[N+2],qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n;cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i];qm[i]=qm[i-1];
    qm[i]+=aa[i];
  }
  long now=0,ans=-1e4,one,two,thr;
  for(long i=0;i<=n;i++)
  {
    now+=aa[i];long sum=0,mx=-1e14,lt=i,a,b;
    for(long j=i+1;j<=n;j++)
    {
      sum+=aa[j];
      if(sum<0)
      {
        sum=0;lt=j;
      }
      if(sum>mx)
      {
        mx=sum;a=lt;b=j;
      }
    }
    if(mx==0)a=n,b=n;
    if(now+mx-(qm[n]-qm[i]-mx)>ans)
    {
      ans=now+mx-(qm[n]-qm[i]-mx);
      one=i;two=a;thr=b;
    }
  }
  cout<<one<<" "<<two<<" "<<thr<<endl;
  return 0;
}