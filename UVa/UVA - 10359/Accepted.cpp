/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-07-21 20:09:39                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 10                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10359
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n;
string dp[255];
string add(string a,string b)
{
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  if(b.size()>a.size())swap(a,b);

  string ret;
  int c=0,s;
  for(int i=0;i<a.size();i++)
  {
    if(i>=b.size())
    {
      s=a[i]-'0'+c;
      c=s/10;
      s=s%10;
      ret.push_back(s+'0');
    }
    else
    {
      s=a[i]+b[i]-'0'-'0'+c;
      c=s/10;
      s=s%10;
      ret.push_back(s+'0');
    }
  }
  if(c)ret.push_back(c+'0');
  reverse(ret.begin(),ret.end());
  return ret;
}
string dfs(int st)
{
  if(st==n)return "1";
  if(st>n)return "0";
  if(dp[st]!="-1")return dp[st];
  string here="0";
  here=add(dfs(st+2),dfs(st+1));
  here=add(here,dfs(st+2));
  return dp[st]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>n)
  {
    for(int i=0;i<=n;i++)dp[i]="-1";
    cout<<dfs(0)<<endl;
  }
  return 0;
}