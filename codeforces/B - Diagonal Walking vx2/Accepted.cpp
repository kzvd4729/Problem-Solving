/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/07/2018 21:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1036/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long q,n,m,k;cin>>q;
  while(q--)
  {
    cin>>n>>m>>k;
    long mv=min(n,m)+abs(n-m);
    if(mv>k)
    {
      cout<<-1<<endl;
      continue;
    }
    long tt=n+m;
    //if(tt%2)k--;
    if(tt%2==0)
    {
      if(mv%2==0)
      {
        if(k%2==0)cout<<k<<endl;
        else cout<<k-2<<endl;
      }
      else if(mv%2)
      {
        if(k%2)cout<<k<<endl;
        else cout<<k-2<<endl;
      }
    }
    else cout<<k-1<<endl;
  }
  return 0;
}