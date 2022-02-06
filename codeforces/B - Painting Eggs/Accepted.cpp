/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 21:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 934 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/282/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,sum=0;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int a,b;cin>>a>>b;
    sum+=b;
  }
  int rq=sum/1000;
  sum%=1000;
  if(sum>500)rq++;
  if(rq>n)cout<<-1<<endl,exit(0);
  for(int i=1;i<=rq;i++)
    cout<<'A';
  for(int i=rq+1;i<=n;i++)
    cout<<'G';
  cout<<endl;
  return 0;
}