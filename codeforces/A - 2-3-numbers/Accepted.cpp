/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/17/2018 21:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 421 ms                                          memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/953/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ans,l,r;
set<long>st;
map<long,long>mp;
void dfs(long sum)
{
  if(st.find(sum)!=st.end())return ;
  if(sum>=l&&sum<=r)st.insert(sum);
  if(sum>r)return ;
  dfs(sum*2);
  dfs(sum*3);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>l>>r;
  dfs(1);
  cout<<st.size()<<endl;
  return 0;
}