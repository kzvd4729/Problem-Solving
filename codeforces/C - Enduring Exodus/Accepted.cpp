/****************************************************************************************
*  @author: kzvd4729                                         created: May/01/2020 10:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/655/problem/C
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
const int N=1e6;
int qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;string s;cin>>s;s="#"+s;
   for(int i=1;i<=n;i++)
  {
    qm[i]=qm[i-1];if(s[i]=='0')qm[i]++;
  }
  auto ret=[](int i,int j,int n)
  {
    if(i<1)i=1;if(j>n)j=n;
    return qm[j]-qm[i-1];
  };
  int ans=n;
  for(int i=1;i<=n;i++)
  {
    if(s[i]=='1')continue;
    int lo=0,hi=n,md;
    while(hi-lo>2)
    {
      int md=(lo+hi)/2;
      if(ret(i-md,i+md,n)>k)hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      if(ret(i-md,i+md,n)>k)
        break;
    }
    ans=min(ans,md);
  }
  cout<<ans<<endl;
  return 0;
}