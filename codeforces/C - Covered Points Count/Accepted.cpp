/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2018 15:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1000/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,ans[N+2];
pair<long,long>p[N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  n+=n;
  for(long i=1;i<=n;i+=2)
  {
    cin>>p[i].first;
    p[i].second=0;
    cin>>p[i+1].first;
    p[i+1].second=1;
  }
  sort(p+1,p+n+1);
  long pr=0,cnt=0;
  for(long i=1;i<=n;i++)
  {
    if(!p[i].second)
    {
      ans[cnt]+=p[i].first-pr;
      cnt++;
      pr=p[i].first;
    }
    else
    {
      ans[cnt]+=p[i].first-pr+1;
      cnt--;
      pr=p[i].first+1;
    }
  }
  for(long i=1;i<=n/2;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}