/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2018 20:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 998 ms                                          memory_used: 10100 KB                             
*  problem: https://codeforces.com/contest/862/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<int>v;
  for(int i=0;i<=N;i++)v.push_back(i);
   int n,x;cin>>n>>x;
  for(int i=1;i<=70;i++)
  {
    int sum=0;vector<int>ans;
    for(int i=0;i<n-1;i++)
    {
      ans.push_back(v[i]);
      sum^=v[i];vis[v[i]]=1;
    }
    if(vis[sum^x]==0&&(sum^x)<=N)
    {
      cout<<"YES"<<endl;
      for(auto x:ans)
        cout<<x<<" ";
      cout<<(sum^x)<<endl;
      exit(0);
    }
    for(int i=0;i<n-1;i++)vis[v[i]]=0;
    random_shuffle(v.begin(),v.end());
  }
  cout<<"NO"<<endl;
  return 0;
}