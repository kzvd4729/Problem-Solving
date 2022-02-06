/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2019 21:02                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
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
  for(int i=0;i<r;i++)
  {
    if(i%2==0)
    {
      int f=0;
      for(int j=0;j<n;j++)
      {
        if(s[j]=='8'||vis[j])continue;
        vis[j]=1;f=1;break;
      }
      if(!f)ya();
    }
    else
    {
      int f=0;
      for(int j=0;j<n;j++)
      {
        if(s[j]=='8'&&vis[j]==0)
        {
          vis[j]=1;f=1;break;
        }
      }
      if(!f)no();
    }
  }
  for(int i=0;i<n;i++)
  {
    if(vis[i])continue;
    if(s[i]=='8')ya();
  }
  no();
  return 0;
}