/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/18/2019 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/598/problem/A
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
    long n,sum;cin>>n;
    sum=(n*(n+1))/2;
    for(int i=0; ;i++)
    {
      int x=(1<<i);if(x>n)break;
      sum-=x;sum-=x;
    }
    cout<<sum<<endl;
  }
  return 0;
}