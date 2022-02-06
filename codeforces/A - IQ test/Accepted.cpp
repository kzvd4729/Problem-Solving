/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2018 16:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/25/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e2;
int ev,od,eid,oid,n,x;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    if(x%2==0)
    {
      ev++;
      eid=i;
    }
    else
    {
      od++;
      oid=i;
    }
  }
  if(ev==1)cout<<eid;
  else cout<<oid;
   return 0;
}