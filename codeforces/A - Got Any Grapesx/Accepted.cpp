/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1114/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
void no()
{
  cout<<"NO"<<endl;exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x,y,z;cin>>x>>y>>z;
  int a,b,c;cin>>a>>b>>c;
  if(a<x)no();a-=x;
  if(a+b<y)no();
  if(a+b+c<y+z)no();
  cout<<"YES"<<endl;
  return 0;
}