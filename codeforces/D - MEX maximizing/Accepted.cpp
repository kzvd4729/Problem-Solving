/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/22/2020 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1294/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int mod[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x;cin>>n>>x;int rq=0;
  for(int i=1;i<=n;i++)
  {
    int a;cin>>a;mod[a%x]++;
    while(true)
    {
      if(mod[rq%x]){mod[rq%x]--;rq++;}
      else break;
    }
    cout<<rq<<"\n";
  }
  return 0;
}