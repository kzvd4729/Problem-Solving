/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/18/2018 22:32                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1079/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s;cin>>s;
  if(s.size()<=20)
  {
    cout<<1<<" "<<s.size()<<endl;
    cout<<s<<endl;exit(0);
  }
  int a=5,b=s.size()/5,rm=s.size()-a*b;
   cout<<a<<" "<<b<<endl;int pt=0;
  while(a--)
  {
    int mr;
    if(rm)mr=b-1;
    else mr=b;
    while(mr--)
      cout<<s[pt++];
    if(rm)cout<<"*";
    cout<<endl;
    if(rm)rm--;
  }
  return 0;
}