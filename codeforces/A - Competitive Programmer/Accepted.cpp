/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2019 21:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1266/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;int f=0;
    if(s.size()==0)
    {
      if(s=="0")cout<<"red\n";
      else cout<<"cyan\n";
      continue;
    }
    for(int i=0;i<s.size();i++)
    {
      for(int j=0;j<s.size();j++)
      {
        if(i==j)continue;
        int nm=(s[i]-'0')*10+(s[j]-'0');
        if((nm%4==0)&&(nm%10==0))f=1;
      }
    }
    int sm=0;
    for(auto x:s)sm+=x-'0';
    if(sm%3==0&&f)cout<<"red\n";
    else cout<<"cyan\n";
  }
  return 0;
}