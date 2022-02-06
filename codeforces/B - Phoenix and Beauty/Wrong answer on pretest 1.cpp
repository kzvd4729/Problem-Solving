/****************************************************************************************
*  @author: * kzvd4729                                       created: May/01/2020 20:57                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
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
    int n,k;cin>>n>>k;set<int>st;
    for(int i=1;i<=n;i++)cin>>aa[i],st.insert(aa[i]);
     if(st.size()>k)cout<<-1<<"\n";
    else
    {
      k=st.size();
      for(int i=1;i<=k;i++)
      {
        aa[i]=*st.begin();st.erase(*st.begin());
      }
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