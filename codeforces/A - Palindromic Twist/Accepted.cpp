/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2018 08:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1027/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
  int t;cin>>t;
 while(t--)
 {
  int n,f=0;cin>>n;
  string s;cin>>s;
  for(int i=0,j=s.size()-1;i<s.size();i++,j--)
  {
   if(abs(s[i]-s[j])==0||abs(s[i]-s[j])==2);
   else f=1;
  }
  if(f)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
 }
 return 0;
}