/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/08/2021 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1467/problem/A
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
    cout<<9;int in=8;
    for(int i=2;i<=n;i++)
    {
      cout<<in;in=(in+1)%10;
    }
    cout<<endl;
  }
    return 0;
}