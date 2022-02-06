/****************************************************************************************
*  @author: * kzvd4729                                       created: May/01/2020 20:48                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1348/problem/B
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>aa[i];
     int ok=1;
    for(int i=k+1;i<=n;i++)
    {
      int f=0;
      for(int j=1;j<=k;j++)
        if(aa[i]==aa[j])f=1;
      if(f==0){ok=0;break;}
    }
    if(!ok)cout<<-1<<"\n";
    else
    {
      cout<<n*k<<"\n";
      while(n--)
      {
        for(int i=1;i<=k;i++)cout<<aa[i]<<" ";
      }
      cout<<"\n";
    }
  }
  return 0;
}