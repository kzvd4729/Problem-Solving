/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-19 18:19:25                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 12 ms                                           memory_used: 4352 KB                              
*  problem: https://atcoder.jp/contests/abc143/tasks/abc143_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i],fr[aa[i]]++;
   sort(aa+1,aa+n+1);
   for(int i=1;i<=N;i++)
    fr[i]+=fr[i-1];
   long ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      int rt=aa[i]+aa[j]-1,lt=aa[j]-aa[i]+1;
      int ad=fr[rt];if(lt)ad-=fr[lt-1];
       if(aa[i]>=lt&&aa[i]<=rt)ad--;
      if(aa[j]>=lt&&aa[j]<=rt)ad--;
       ans+=ad;
       //cout<<i<<" "<<j<<" "<<fr[aa[i]+aa[j]-1]-2<<endl;
    }
  }
  cout<<ans/3<<endl;
  return 0;
}