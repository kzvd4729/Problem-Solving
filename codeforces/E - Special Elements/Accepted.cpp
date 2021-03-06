/****************************************************************************************
*  @author: * kzvd4729                                       created: May/09/2020 21:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/1352/problem/E
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
const int N=8000;
int aa[N+2];
bitset<N+2>vs;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    vs.reset();
    for(int i=1;i<=n;i++)
    {
      int sm=aa[i];
      for(int j=i+1;j<=n;j++)
      {
        sm+=aa[j];if(sm>N)break;
        vs[sm]=1;
      }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
      if(vs[aa[i]])cnt++;
    cout<<cnt<<"\n";
  }
  return 0;
}