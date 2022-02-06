/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 4554 ms                                         memory_used: 65500 KB                             
*  problem: https://codeforces.com/gym/100009/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
unordered_map<int,int>dp[32];
int dfs(int n,int msk)
{
  if(dp[n].count(msk))return dp[n][msk];
  set<int>st;
  for(int i=0;i<24;i++)
  {
    if(msk&(1<<i))continue;
    int c=i/4+1;
    if(n-c>=0)
      st.insert(dfs(n-c,msk|(1<<i)));
  }
  for(int i=0; ;i++)
    if(st.find(i)==st.end())return dp[n][msk]=i;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s;
  while(getline(cin,s))
  {
    //cout<<"s ="<<s<<endl;
    int sum=0,tr=1,msk=0;
    for(auto x:s)
    {
      int c=x-'0';sum+=c;
      for(int i=4*(c-1);i<4*c;i++)
      {
        if(msk&(1<<i))continue;
        msk|=(1<<i);break;
      }
      if(sum>31)
      {
        if(tr)cout<<s<<" B"<<endl;
        else cout<<s<<" A"<<endl;
      }
      tr^=1;
    }
    int x=dfs(31-sum,msk);
    //cout<<" "<<x<<endl;
    if(tr)
    {
      if(x)cout<<s<<" A"<<endl;
      else cout<<s<<" B"<<endl;
    }
    else
    {
      if(x)cout<<s<<" B"<<endl;
      else cout<<s<<" A"<<endl;
    }
  }
  return 0;
}