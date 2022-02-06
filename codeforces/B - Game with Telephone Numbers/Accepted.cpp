/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2019 21:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1155/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2];
void no(void)
{
  cout<<"NO"<<endl,exit(0);
}
void ya(void)
{
  cout<<"YES"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  string s;cin>>s;
  int r=(n-11);
  int cnt=r/2;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='8')continue;
    if(cnt)
    {
      vis[i]=1;cnt--;
    }
  }
  cnt=r/2;
  for(int i=0;i<n;i++)
  {
    if(s[i]!='8')continue;
    if(cnt)
    {
      vis[i]=1;cnt--;
    }
  }
  for(int i=0;i<n;i++)
  {
    if(vis[i])continue;
    if(s[i]=='8')ya();
    else no();
  }
  return 0;
}