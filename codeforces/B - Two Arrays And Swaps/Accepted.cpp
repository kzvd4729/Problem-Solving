/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2020 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 11500 KB                             
*  problem: https://codeforces.com/contest/1353/problem/B
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;int sm=0;
    for(int i=1;i<=n;i++)cin>>aa[i],sm+=aa[i];
    for(int i=1;i<=n;i++)cin>>bb[i];
    sort(aa+1,aa+n+1),sort(bb+1,bb+n+1);
     for(int i=1;i<=n;i++)
    {
      if(!k)break;if(bb[n-i+1]<aa[i])break;
      sm+=bb[n-i+1]-aa[i];k--;
    }
    cout<<sm<<endl;
  }
  return 0;
}