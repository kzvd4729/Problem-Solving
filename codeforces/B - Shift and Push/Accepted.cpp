/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/17/2019 19:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 234 ms                                          memory_used: 8900 KB                              
*  problem: https://codeforces.com/gym/101059/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<int>pos[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    pos[x].push_back(i);
  }
  int ans=1e9;
  for(int i=1;i<=N;i++)
  {
    int mx=0;if(pos[i].size()==0)continue;
    for(int j=1;j<pos[i].size();j++)
      mx=max(mx,pos[i][j]-pos[i][j-1]-1);
    mx=max(mx,pos[i][0]+n-pos[i][pos[i].size()-1]-1);
    ans=min(ans,mx);
  }
  cout<<ans+n<<endl;
  return 0;
}