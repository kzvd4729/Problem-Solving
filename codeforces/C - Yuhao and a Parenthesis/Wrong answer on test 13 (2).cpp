/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/05/2019 14:41                        
*  solution_verdict: Wrong answer on test 13                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1097/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int ps[N+2],ng[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int zero=0;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    int bl=0;int mn=1e9;
    for(auto x:s)
    {
      if(x=='(')bl++;
      else bl--;
      mn=min(mn,bl);
    }
    if(bl==0)
    {
      if(mn>=0)zero++;
    }
    else if(bl>0)
    {
      if(mn>=0)ps[bl]++;
    }
    else
    {
      if(mn>=bl)ng[-bl]++;
    }
  }
  int ans=zero/2;
  for(int i=1;i<=n;i++)
    ans+=min(ps[i],ng[i]);
  cout<<ans<<endl;
  return 0;
}