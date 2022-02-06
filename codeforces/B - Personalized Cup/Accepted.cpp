/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/18/2018 22:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
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
  int a,b,rm;
  if(s.size()>80)a=5;
  else if(s.size()>60)a=4;
  else if(s.size()>40)a=3;
  else if(s.size()>20)a=2;
  b=(s.size()+a-1)/a;rm=a*b-s.size();
   cout<<a<<" "<<b<<endl;int pt=0;
  //cout<<s.size()<<" "<<rm<<endl;
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