/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/24/2019 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1152/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;int od1=0,od2=0,ev1=0,ev2=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x%2)od1++;
    else ev1++;
  }
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    if(x%2)od2++;
    else ev2++;
  }
  cout<<min(ev1,od2)+min(ev2,od1)<<endl;
  return 0;
}