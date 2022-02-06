/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1037/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int x,i;cin>>x;
  for(i=0; ;i++)
    if((1<<i)>x)break;
  cout<<i<<endl;
  return 0;
}