/****************************************************************************************
*  @author: kzvd4729                                         created: May/27/2020 20:44                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1358/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
long sm(long x)
{
  return x*(x+1)/2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x;cin>>n>>x;
  for(int i=1;i<=n;i++)cin>>aa[i],aa[n+i]=aa[i];
   long ans=0,cur=0,now=0;int pt=1;
  for(int i=1;i<=n+n;i++)
  {
    cur+=aa[i];now+=sm(aa[i]);
    while(cur>x)
    {
      cur-=aa[pt];now-=sm(aa[pt]);
      pt++;
    }
    ans=max(ans,now);
    if(pt>1)ans=max(ans,now+sm(aa[pt-1])-sm(aa[pt-1]-x+cur));
  }
  cout<<ans<<endl;
  return 0;
}