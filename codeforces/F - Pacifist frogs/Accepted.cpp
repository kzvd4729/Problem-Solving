/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/39/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int fr[N+2],ms[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,f,m;cin>>n>>f>>m;
  for(int i=1;i<=f;i++)
    cin>>fr[i];
  for(int i=1;i<=m;i++)
    cin>>ms[i];
  int mx=-1;
  for(int i=1;i<=f;i++)
  {
    int cnt=0;
    for(int j=1;j<=m;j++)
    {
      if(ms[j]%fr[i])cnt++;
    }
    mx=max(mx,cnt);
  }
  vector<int>ans;
  for(int i=1;i<=f;i++)
  {
    int cnt=0;
    for(int j=1;j<=m;j++)
    {
      if(ms[j]%fr[i])cnt++;
    }
    if(cnt==mx)ans.push_back(i);
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}