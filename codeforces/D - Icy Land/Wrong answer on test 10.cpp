/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2019 13:42                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 23500 KB                             
*  problem: https://codeforces.com/gym/102001/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>s[i];
  int ans=0;
  for(int i=1;i<n-1;i++)
  {
    for(int j=1;j<m-1;j++)
      ans+=s[i][j]=='.';
  }
  cout<<ans<<endl;
    return 0;
}