/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2018 22:52                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/934/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e2;
long p,k;
map<pair<long,long>,long>mp;
void dfs(long st,long co,long nn,vector<long>ans)
{
  if(st==nn-1)
  {
    if(co+p<k&&co+p>=0)
    {
      ans.push_back(co+p);
      reverse(ans.begin(),ans.end());
      cout<<ans.size()<<endl;
      for(auto x:ans)
        cout<<x<<" ";
      cout<<endl;
      exit(0);
    }
    return ;
  }
  long i=0;if(st==0)i=1;
  for( ;i<k;i++)
  {
    ans.push_back(i);
    dfs(st+1,(i-co)*k,nn,ans);
    ans.pop_back();
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>p>>k;vector<long>v;
  for(int i=1;i<=2000;i++)
    dfs(0,0,i,v);
  cout<<-1<<endl;
  return 0;
}