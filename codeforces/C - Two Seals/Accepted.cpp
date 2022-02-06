/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 15:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 8100 KB                              
*  problem: https://codeforces.com/contest/837/problem/C
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
int aa[N+2],bb[N+2];
int ans,a,b;
void upd(int i,int j)
{
  if(aa[i]+aa[j]<=a&&max(bb[i],bb[j])<=b)ans=max(ans,aa[i]*bb[i]+aa[j]*bb[j]);
  if(bb[i]+bb[j]<=b&&max(aa[i],aa[j])<=a)ans=max(ans,aa[i]*bb[i]+aa[j]*bb[j]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>a>>b;
  for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i];
   for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      upd(i,j);
      swap(aa[j],bb[j]);upd(i,j);
      swap(aa[j],bb[j]);
      swap(aa[i],bb[i]);upd(i,j);
      swap(aa[j],bb[j]);upd(i,j);
    }
  }
  cout<<ans<<endl;
    return 0;
}