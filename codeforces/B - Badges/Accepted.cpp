/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/04/2019 15:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1214/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int b,g,n;cin>>b>>g>>n;
  b=min(b,n);g=min(g,n);
  int cnt=0;
  for(int i=0;i<=b;i++)
  {
    int gg=n-i;
    if(gg>g)continue;
    cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}