/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2019 13:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102001/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int ans=0;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    if(s=="LIE")ans^=1;
  }
  if(!ans)cout<<"TRUTH\n";
  else cout<<"LIE\n";
    return 0;
}