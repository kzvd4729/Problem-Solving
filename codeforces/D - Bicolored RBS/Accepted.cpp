/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2019 21:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1300 KB                              
*  problem: https://codeforces.com/contest/1167/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  int dp=0,mx=0;
  for(auto x:s)
  {
    if(x=='(')dp++;
    else dp--;mx=max(mx,dp);
  }
  vector<int>ans(n);dp=0;mx/=2;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='(')
    {
      dp++;if(dp<=mx)ans[i]=1;
    }
    else
    {
      if(dp<=mx)ans[i]=1;
      dp--;
    }
  }
  for(int i=0;i<n;i++)
    cout<<ans[i];
  cout<<endl;
  return 0;
}