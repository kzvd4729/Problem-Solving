/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/16/2019 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1154/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int a,b,c,d;cin>>a>>b>>c>>d;
  if(a>d)swap(a,d);
  if(b>d)swap(b,d);
  if(c>d)swap(c,d);
  int e=a-b;
  int f=e+c;
  f/=2;
  int bb=f;
  int aa=a-bb;
  int cc=d-aa-bb;
  cout<<aa<<" "<<bb<<" "<<cc<<endl;
  return 0;
}