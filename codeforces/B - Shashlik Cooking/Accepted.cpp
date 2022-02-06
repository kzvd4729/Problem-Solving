/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/05/2018 23:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1040/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,kk,st;cin>>n>>k;kk=k+k+1;
   int rm=n%kk;
  if(rm&&rm<=k)st=1;
  else st=k+1;
  vector<int>ans;
  while(st<=n)
  {
    ans.push_back(st);
    st+=kk;
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)cout<<x<<" ";
  cout<<endl;
  return 0;
}