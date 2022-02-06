/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/07/2019 21:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1133/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  int a=(s[0]-'0')*10+s[1]-'0';
  int b=(s[3]-'0')*10+s[4]-'0';
   cin>>s;
  int c=(s[0]-'0')*10+s[1]-'0';
  int d=(s[3]-'0')*10+s[4]-'0';
   int m1=a*60+b,m2=c*60+d;
  int df=m2-m1;df/=2;
   //cout<<df<<endl;
   a+=df/60;b+=df%60;
  if(b>=60)a++,b-=60;
  if(a<10)cout<<0<<a<<":";
  else cout<<a<<":";
  if(b<10)cout<<0<<b<<endl;
  else cout<<b<<endl;
   return 0;
}