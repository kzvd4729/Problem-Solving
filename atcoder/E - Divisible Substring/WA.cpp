/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-07 23:49:46                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 6 ms                                            memory_used: 2580 KB                              
*  problem: https://atcoder.jp/contests/abc158/tasks/abc158_e
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2],dd[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,p;cin>>n>>p;string s;cin>>s;
   aa[0]++;int nm=0;
  for(int i=0;i<n;i++)
  {
    nm=(nm*10+s[i]-'0')%p;
    aa[nm]++;
  }
  long ans=0;nm=0;
  for(int i=0;i<n;i++)
  {
    nm=(nm*10+s[i]-'0')%p;
    aa[nm]--;ans+=aa[nm];
  }
  cout<<ans<<endl;
   return 0;
}