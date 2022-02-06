/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2019 15:33                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/866/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
struct data
{
  long sl,a,b;
}aa[N+2];
bool cmp(data A,data B)
{
  return A.a-A.b>B.a-B.b;
}
long cal(long asl,long n)
{
  long ret=0;
  for(long i=1;i<=n;i++)
  {
    long mn=min(asl,aa[i].sl);
    ret+=mn*aa[i].a;asl-=mn;
    ret+=(aa[i].sl-mn)*aa[i].b;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,s;cin>>n>>s;long tt=0;
  for(long i=1;i<=n;i++)
    cin>>aa[i].sl>>aa[i].a>>aa[i].b,tt+=aa[i].sl;
  sort(aa+1,aa+n+1,cmp);
  /*cout<<endl;
  for(int i=1;i<=n;i++)
  {
    cout<<aa[i].sl<<" "<<aa[i].a<<" "<<aa[i].b<<endl;
  }*/
  long pzt=(tt+s-1)/s;
   long tta=0,ttb=0;long ans=0;
  for(long i=1;i<=n;i++)
  {
    if(aa[i].a>aa[i].b)
      tta+=aa[i].sl,ans+=aa[i].sl*aa[i].a;
    else ttb+=aa[i].sl,ans+=aa[i].sl*aa[i].b;
  }
  long pza=(tta+s-1)/s;
  long pzb=(ttb+s-1)/s;
  //cout<<pzt<<endl;
  //cout<<pza<<" "<<pzb<<endl;
  if(pza+pzb==pzt)cout<<ans<<endl,exit(0);
  //cout<<cal(pza*s-s,n)<<endl;
  cout<<max(cal(pza*s-s,n),cal(pza*s,n))<<endl;
   return 0;
}