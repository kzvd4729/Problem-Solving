/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2020 16:55                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 39100 KB                             
*  problem: https://codeforces.com/contest/613/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long n,a,aa[N+2],bb[N+2],qm[N+2];
bool ok(long md,long mm)
{
  long id=lower_bound(aa+1,aa+n+1,md)-aa;
  id--;
  if(id*md-qm[id]<=mm)return true;
  return false;
}
pair<long,long>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long c1,c2,m;cin>>n>>a>>c1>>c2>>m;
   for(long i=1;i<=n;i++)cin>>aa[i],bb[i]=aa[i];
  sort(aa+1,aa+n+1);
    for(long i=1;i<=n;i++)
    qm[i]=qm[i-1]+aa[i];
   long pt=n,mm=m;
  for(long i=n;i>=1;i--)if(aa[i]==a)pt--;
  long ans=(n-pt)*c1+aa[1]*c2,cnt=aa[1];
  aa[n+1]=a;
  for(long i=pt+1;i>=1;i--)
  {
    mm-=(a-aa[i]);if(mm<0)break;
    long lo=aa[1],hi=a,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(ok(md,mm))lo=md;
      else hi=md;
    }
    for(md=lo;md<=hi;md++)
      if(!ok(md,mm))break;
    md--;
     if((n-i+1)*c1+md*c2>ans)
      ans=(n-i+1)*c1+md*c2,cnt=md;
  }
  for(long i=1;i<=n;i++)
  {
    if(bb[i]<cnt)m-=(cnt-bb[i]),bb[i]=cnt;
    pp[i]={bb[i],i};
  }
  sort(pp+1,pp+n+1);
  for(long i=n;i>=1;i--)
  {
    if(a-pp[i].first<m)
      m-=(a-pp[i].first),pp[i].first=a;
  }
  sort(pp+1,pp+n+1,[](pair<long,long>a,pair<long,long>b){
    return a.second<b.second;
    });
  cout<<ans<<endl;
  for(long i=1;i<=n;i++)
    cout<<pp[i].first<<" ";
  cout<<endl;
  return 0;
}