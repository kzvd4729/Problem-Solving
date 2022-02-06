/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2018 17:32                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
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
  int n;cin>>n;
  for(int i=n;i>0;i--)
  {
    int lm=31-__builtin_clz(i),req=0;
    for(int j=0;j<lm;j++)
      if(!(i&(1<<j)))req|=(1<<j);
    int here=req;
    for(int j=lm+1; ;j++)
    {
      int tmp=req|(1<<j);
      if(tmp>n)break;
      if(vis[tmp]==0)
        here=tmp;
    }
    vis[here]=1;
    cout<<i<<" "<<here<<endl;
  }
  return 0;
}