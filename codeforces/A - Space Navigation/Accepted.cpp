/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/05/2021 20:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1481/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int x,y;cin>>x>>y;
    string s;cin>>s;
     map<char,int>mp;
    for(auto c:s)mp[c]++;
     int f=0;
    if(x>=0&&y>=0)
    {
      x=abs(x),y=abs(y);
      f=(mp['R']>=x&&mp['U']>=y);
    }
    else if(x<=0&&y>=0)
    {
      x=abs(x),y=abs(y);
      f=(mp['L']>=x&&mp['U']>=y);
    }
    else if(x<=0&&y<=0)
    {
      x=abs(x),y=abs(y);
      f=(mp['L']>=x&&mp['D']>=y);
    }
    else if(x>=0&&y<=0)
    {
      x=abs(x),y=abs(y);
      f=(mp['R']>=x&&mp['D']>=y);
    }
    if(f)cout<<"YES\n";else cout<<"NO\n";
   }
  return 0;
}