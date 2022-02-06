/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2018 17:51                        
*  solution_verdict: Wrong answer on test 13                 language: GNU C++14                               
*  run_time: 404 ms                                          memory_used: 10100 KB                             
*  problem: https://codeforces.com/contest/288/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>pr;
  for(int i=n;i>0;i--)
  {
    int lm=31-__builtin_clz(i),req=0;
    for(int j=0;j<lm;j++)
      if(!(i&(1<<j)))req|=(1<<j);
    int here=req;
    for(int j=lm+1; ;j++)
    {
      req|=(1<<j);
      if(req>n)break;
      if(vis[req]==0)
        here=req;
    }
    vis[here]=1;
    pr.push_back(here);
  }
  for(int i=0;i<=n;i++)if(!vis[i])pr.push_back(i);
  reverse(pr.begin(),pr.end());
  int sum=0;
  for(int i=0;i<=n;i++)
    sum+=(i^pr[i]);
  cout<<sum<<endl;
  for(auto x:pr)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}