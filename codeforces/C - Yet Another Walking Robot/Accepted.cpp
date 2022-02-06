/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/04/2020 20:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 8300 KB                              
*  problem: https://codeforces.com/contest/1296/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
map<pair<int,int>,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;mp.clear();
    int x=0,y=0;mp[{x,y}]=1;
    string s;cin>>s;int mn=inf,l,r;
    for(int i=1;i<=n;i++)
    {
      char c=s[i-1];
      if(c=='L')x--;else if(c=='R')x++;
      else if(c=='U')y++;else if(c=='D')y--;
       int p=mp[{x,y}];
      if(p&&i-p<mn)
      {
        mn=i-p;l=p,r=i;
      }
      mp[{x,y}]=i+1;
    }
    if(mn==inf)cout<<-1<<"\n";
    else cout<<l<<" "<<r<<"\n";
  }
    return 0;
}