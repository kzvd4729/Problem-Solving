/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 22:31                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/282/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2][2][2];
string a,b;
void dfs(int st,int now,int nxt)
{
  if(st==b.size()-1)
  {
    if(now==b.back()-'0')
      cout<<"YES"<<endl,exit(0);
    return ;
  }
  if(vis[st][now][nxt])return ;
  vis[st][now][nxt]=1;
  int xr=now^nxt,rr=now|nxt;
  if(b[st]-'0'==xr)
    dfs(st+1,rr,a[st+2]-'0');
  else if(b[st]-'0'==rr)
    dfs(st+1,xr,a[st+2]-'0');
  else if(b[st]-'0'==now)
    dfs(st+1,nxt,a[st+2]-'0');
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b;if(a.size()!=b.size())cout<<"NO"<<endl,exit(0);
  a.push_back('0');a.push_back('0');
  dfs(0,a[0]-'0',a[1]-'0');
   cout<<"NO"<<endl;
   return 0;
}