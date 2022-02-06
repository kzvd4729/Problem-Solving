/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 22:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/282/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
void no(void)
{
  cout<<"NO"<<endl,exit(0);
}
void ya(void)
{
  cout<<"YES"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;
  if(a.size()!=b.size())no();
  if(a==b)ya();
   int one=0;
  for(auto x:a)if(x=='1')one++;
  if(!one)no();
   int two=0;
  for(auto x:b)if(x=='1')two++;
  if(!two)no();
   ya();
   return 0;
}