/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/30/2019 18:52                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/713/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3,inf=1e9;
int aa[N+2],n;
unordered_map<int,long>mp[N+2];
long dfs(int i,int l)
{
 if(i>n)return 0;
 if(mp[i].count(l))return mp[i][l];
  long ret=1e17;
 if(aa[i]>l)ret=dfs(i+1,aa[i]);
 ret=min(ret,abs((l+1)-aa[i])+dfs(i+1,l+1));
 return mp[i][l]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
   cin>>aa[i];
   //aa[i]=rand();
  }
   long ans=1e17;
  for(int i=1;i<=n;i++)
  {
   ans=min(ans,abs(aa[1]-(aa[i]-i+1))+dfs(2,aa[i]-i+1));
   //cout<<abs(aa[1]-(aa[i]-i+1))<<" "<<dfs(2,aa[i]-i+1)<<" "<<aa[i]-i+1<<endl;
  }
  cout<<ans<<endl;
     return 0;
}