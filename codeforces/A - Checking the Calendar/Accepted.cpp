/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2018 22:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/724/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
map<string,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  mp["monday"]=1;
  mp["tuesday"]=2;
  mp["wednesday"]=3;
  mp["thursday"]=4;
  mp["friday"]=5;
  mp["saturday"]=6;
  mp["sunday"]=7;
   string s1,s2;cin>>s1>>s2;
  int df=(mp[s2]+7-mp[s1])%7;
  if(df==0||df==2||df==3)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
   return 0;
}