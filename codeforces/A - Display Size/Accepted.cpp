/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 18:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/747/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int aa,bb;
  for(int i=1;i<=n;i++)
  {
   if(n%i)continue;int a=i,b=n/i;
   if(a>b)continue;
   aa=a,bb=b;
  }
  cout<<aa<<" "<<bb<<endl;
  return 0;
}