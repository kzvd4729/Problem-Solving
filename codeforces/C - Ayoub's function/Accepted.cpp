/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/13/2020 21:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1301/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,m;cin>>n>>m;
    long ans=(n*(n+1))/2;
     long on=m,zr=n-m;
     long sg=zr/(on+1);
     long md=zr%(on+1);
     ans-=((sg*(sg+1))/2)*(on+1-md);sg++;
    ans-=((sg*(sg+1))/2)*md;
    cout<<ans<<"\n";
  }
  return 0;
}