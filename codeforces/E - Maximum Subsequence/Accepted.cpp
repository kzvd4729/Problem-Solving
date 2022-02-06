/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/17/2018 13:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/888/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,m,aa[3],bb[3][40];
vector<int>vv[3];
void dfs(int id,int st,int sum)
{
  if(st>aa[id])
  {
    vv[id].push_back(sum);return ;
  }
  dfs(id,st+1,(sum+bb[id][st])%m);
  dfs(id,st+1,sum);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;aa[0]=n/2;aa[1]=n-aa[0];
  for(int i=1;i<=aa[0];i++)
    cin>>bb[0][i];
  for(int i=1;i<=aa[1];i++)
    cin>>bb[1][i];
  dfs(0,1,0);dfs(1,1,0);
  sort(vv[0].begin(),vv[0].end());
  sort(vv[1].begin(),vv[1].end());
  int ans=0;
  for(auto x:vv[0])
  {
    int id=lower_bound(vv[1].begin(),vv[1].end(),m-x)-vv[1].begin();
    if(!id)ans=max(ans,x);
    else ans=max(ans,x+vv[1][id-1]);
  }
  cout<<ans<<endl;
  return 0;
}