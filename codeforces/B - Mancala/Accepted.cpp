/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/23/2018 18:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/975/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=20;
long n=14,aa[N+2],tmp[N+2];
long ck(long id)
{
  for(long i=1;i<=n;i++)tmp[i]=aa[i];tmp[id]=0;
  long add=aa[id]/n;
  for(long i=1;i<=n;i++)
    tmp[i]+=add;
  long ex=aa[id]%n;
  while(ex)
  {
    id++;if(id==n+1)id=1;
    tmp[id]++;ex--;
  }
  long ret=0;
  for(long i=1;i<=n;i++)
  {
    if(tmp[i]%2==0)ret+=tmp[i];
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(long i=1;i<=n;i++)
    cin>>aa[i];
  long ans=0;
  for(long i=1;i<=n;i++)
    ans=max(ans,ck(i));
  cout<<ans<<endl;
   return 0;
}