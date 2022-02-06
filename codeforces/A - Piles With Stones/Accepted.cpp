/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/30/2018 14:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1013/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e8;
const int N=1e6;
int x,s1,s2,n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    s1+=x;
  }
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    s2+=x;
  }
  if(s2<=s1)cout<<"Yes"<<endl;
  else cout<<"NO"<<endl;
   return 0;
}