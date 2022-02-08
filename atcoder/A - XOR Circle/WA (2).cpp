/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-14 18:58:12                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 40 ms                                           memory_used: 3840 KB                              
*  problem: https://atcoder.jp/contests/agc035/tasks/agc035_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
map<int,int>fr;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,on=1,cnt=0;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;on=x;
    if(!fr[x])cnt++;
    fr[x]++;
  }
  if(cnt==1&&!on)cout<<"Yes"<<endl,exit(0);
  if(cnt!=3||n%3)cout<<"No"<<endl,exit(0);
  for(auto x:fr)
    if(x.second!=n/3)cout<<"No"<<endl,exit(0);
  cout<<"Yes"<<endl;
   return 0;
}