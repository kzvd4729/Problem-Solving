/****************************************************************************************
*  @author: * kzvd4729                                       created: Aug/20/2019 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1204/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();
   if(n==1&&s[0]=='0')cout<<0<<endl,exit(0);
   int tw=1;
  for(int i=1;i<n;i++)
    if(s[i]=='1')tw=0;
  if(n%2==0)tw=0;
   cout<<(n+1)/2-tw<<endl;
   return 0;
}