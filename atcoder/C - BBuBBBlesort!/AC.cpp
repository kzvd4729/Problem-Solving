/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-05-02 13:33:54                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 37 ms                                           memory_used: 6656 KB                              
*  problem: https://atcoder.jp/contests/agc003/tasks/agc003_c
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
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int ans=0;set<int>st;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
    if(i%2)st.insert(aa[i]);
  }
  sort(aa+1,aa+n+1);
  for(int i=1;i<=n;i+=2)if(st.find(aa[i])==st.end())ans++;
  cout<<ans<<endl;
  return 0;
}