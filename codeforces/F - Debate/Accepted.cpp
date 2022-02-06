/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/20/2018 14:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/1070/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<int>onon,onzr,zron,zrzr;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string s;int x;cin>>s>>x;
    if(s=="11")onon.push_back(x);
    else if(s=="10")onzr.push_back(x);
    else if(s=="01")zron.push_back(x);
    else zrzr.push_back(x);
  }
  sort(onon.begin(),onon.end());
  sort(onzr.begin(),onzr.end());
  sort(zron.begin(),zron.end());
  sort(zrzr.begin(),zrzr.end());
   int ans=0,ex=0;
  for(auto x:onon)
  {
    ans+=x;ex++;
  }
  while(true)
  {
    if(onzr.size()==0)break;
    if(zron.size()==0)break;
    ans+=onzr.back();onzr.pop_back();
    ans+=zron.back();zron.pop_back();
  }
  while(onzr.size())
  {
    zrzr.push_back(onzr.back());onzr.pop_back();
  }
  while(zron.size())
  {
    zrzr.push_back(zron.back());zron.pop_back();
  }
  sort(zrzr.begin(),zrzr.end());
  while(true)
  {
    if(ex==0||zrzr.size()==0)break;
    ans+=zrzr.back();zrzr.pop_back();
    ex--;
  }
  cout<<ans<<endl;
  return 0;
}