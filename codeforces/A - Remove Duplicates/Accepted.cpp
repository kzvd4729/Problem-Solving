/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2018 12:25                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 3500 KB                              
*  problem: https://codeforces.com/contest/978/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[55],vis[10004];
vector<int>ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
   for(int i=n;i>=1;i--)
  {
    if(vis[arr[i]]==0)
      ans.push_back(arr[i]);
    vis[arr[i]]=1;
  }
  cout<<ans.size()<<endl;
  for(int i=ans.size()-1;i>=0;i--)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}