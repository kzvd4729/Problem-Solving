/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1088/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int x;cin>>x;
   for(int i=1;i<=1000;i++)
  {
    for(int j=1;j<=1000;j++)
    {
      if((i*j>x)&&(i%j==0)&&(i/j)<x)
      {
        cout<<i<<" "<<j<<endl;exit(0);
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}