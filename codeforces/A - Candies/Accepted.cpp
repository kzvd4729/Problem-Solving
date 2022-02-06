/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2020 19:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1343/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=2; ;i++)
    {
      int x=(1<<i)-1;
      if(n%x==0){cout<<n/x<<"\n";break;}
    }
  }
  return 0;
}