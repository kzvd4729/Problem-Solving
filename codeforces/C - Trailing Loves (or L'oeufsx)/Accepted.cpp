/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1114/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int cnt[N+2];long n;
long cal(long x)
{
  long ml=1,ret=0;
  while(true)
  {
    if((n/ml)<x)break;
    ml*=x;
    ret+=n/ml;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long b;cin>>n>>b;int id=-1;
  long sq=sqrt(b+1);vector<long>v;
  for(int i=2;i<=sq;i++)
  {
    if(b%i==0)
    {
      v.push_back(i);
      ++id;
    }
    while(b%i==0)
    {
      b/=i;cnt[id]++;
    }
  }
  if(b>1)
  {
    v.push_back(b);
    cnt[++id]++;
  }
  long ans=1e18;id=0;
  for(auto x:v)
    ans=min(ans,cal(x)/cnt[id++]);
  cout<<ans<<endl;
  return 0;
}