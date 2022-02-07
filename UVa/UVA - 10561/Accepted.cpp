/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-09 21:55:55                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10561
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long 
using namespace std;
const int N=1e6;
int dp[200+2][2][2];
int dfs(int lo,int hi,int l,int r)
{
  //if(l==0&&r==0)assert(0);
  if(dp[hi-lo][l][r]!=-1)return dp[hi-lo][l][r];
  set<int>st;
  for(int i=lo+2;i<=hi-2;i++)
  {
    st.insert(dfs(lo,i-1,l,1)^dfs(i+1,hi,1,r));
  }
  if(hi-lo+1>=3)
  {
    if(l==0)st.insert(dfs(lo+1,hi,1,r));
    if(r==0)st.insert(dfs(lo,hi-1,l,1));
  }
  int ret;
  for(int i=0; ;i++)if(st.find(i)==st.end()){ret=i;break;}
  //cout<<lo<<" "<<hi<<" "<<l<<" "<<r<<" "<<ret<<endl;
  return dp[hi-lo][l][r]=ret;
}
int cal(string s)
{
  //cout<<s<<endl;
  for(int i=0;i<s.size()-2;i++)
  {
    int cnt=0;cnt+=(s[i]=='X');
    cnt+=(s[i+1]=='X');cnt+=(s[i+2]=='X');
    if(cnt>=2)return 1;
  }
  int l=0,xx=0;
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='X')
    {
      if(l<=i-1)
      {
        xx^=dfs(l,i-1,(bool)(l),1);
        //cout<<dfs(l,i-1,(bool)(l),1)<<endl;
      }
      l=i+1;
    }
  }
  if(l<(int)s.size())
  {
    xx^=dfs(l,(int)s.size()-1,(bool)(l),0);
  }
  return xx;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  memset(dp,-1,sizeof dp);
  int t,tc=0;cin>>t;
  while(t--)
  {
    string s;cin>>s;int f=0;vector<int>ans;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='X')continue;int cnt=1;
      for(int j=i+1;j<s.size();j++)
      {
        if(s[j]=='X')cnt++;else break;
      }
      for(int j=i-1;j>=0;j--)
      {
        if(s[j]=='X')cnt++;else break;
      }
      if(cnt>=3)ans.push_back(i+1);
    }
    //s[5]='X';
    //cout<<cal(s)<<endl;exit(0);
    if((int)ans.size()==0)
    {
      for(int i=0;i<s.size();i++)
      {
        if(s[i]=='X')continue;
        s[i]='X';
        if(cal(s)==0)ans.push_back(i+1);
        s[i]='.';
      }
    }
    if(ans.size()==0)cout<<"LOSING"<<endl;
    else cout<<"WINNING"<<endl;
    if(ans.size()>0)cout<<ans[0];
    for(int i=1;i<ans.size();i++)cout<<" "<<ans[i];
      cout<<endl;
  }

  return 0;
}