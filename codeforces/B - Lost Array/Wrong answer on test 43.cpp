/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/28/2018 21:55                        
*  solution_verdict: Wrong answer on test 43                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1043/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int aa[N+2],xx[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int ans=0;vector<int>pr;
  for(int k=1;k<=n;k++)
  {
    memset(xx,-1,sizeof(xx));
    xx[0]=aa[1];int f=0;
    for(int j=2;j<=n;j++)
    {
      if(xx[(j-1)%k]==-1)
      {
        xx[(j-1)%k]=aa[j]-aa[j-1];
      }
      else
      {
        if(aa[j]!=xx[(j-1)%k]+aa[j-1])f=1;
      }
    }
    if(f==0)
    {
      ans++;pr.push_back(k);
    }
  }
  cout<<ans<<endl;
  for(auto x:pr)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}