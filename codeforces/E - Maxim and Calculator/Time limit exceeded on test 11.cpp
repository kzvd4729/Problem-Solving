/****************************************************************************************
*  @author: kzvd4729                                         created: May/10/2019 19:02                        
*  solution_verdict: Time limit exceeded on test 11          language: GNU C++14                               
*  run_time: 4000 ms                                         memory_used: 143100 KB                            
*  problem: https://codeforces.com/contest/261/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int l,r,p;set<int>st;
map<int,int>mp[102][102];
void dfs(int mv,int b,int a)
{
  if(a>=l)st.insert(a);
  if(mv==p)return ;
  if(mp[mv][b][a])return ;mp[mv][b][a]=1;
  dfs(mv+1,b+1,a);
  if((a*1LL)*b<=r)dfs(mv+1,b,a*b);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>l>>r>>p;
  dfs(0,0,1);cout<<st.size()<<endl;
   return 0;
}