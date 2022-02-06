/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2019 16:00                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/616/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;int mx=-1,a,b,ls=1,cnt=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];fr[aa[i]]++;
    if(fr[aa[i]]==1)cnt++;
    while(cnt>k)
    {
      fr[aa[ls]]--;
      if(fr[aa[ls]]==0)cnt--;
      ls++;
    }
    if(cnt==k)
    {
      int ds=i-ls+1;
      if(ds>mx)
      {
        mx=ds;a=ls,b=i;
      }
    }
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}