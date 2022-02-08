/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-01 18:26:12                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 273 ms                                          memory_used: 768 KB                               
*  problem: https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
vector<string>v;
void gen(string s)
{
  if(s.size()==3)
  {
    v.push_back(s);return ;
  }
  for(char i='0';i<='9';i++)
  {
    s.push_back(i);gen(s);
    s.pop_back();
  }
}
int dp[N+2][3];
bool cal(string s,string a)
{
  //cout<<a<<endl;
  int n=s.size();
  for(int i=1;i<=n;i++)
  {
    dp[i][2]=dp[i-1][2];dp[i][1]=dp[i-1][1];dp[i][0]=dp[i-1][0];
    if(s[i-1]==a[2])dp[i][2]|=dp[i-1][1];
    if(s[i-1]==a[1])dp[i][1]|=dp[i-1][0];
    if(s[i-1]==a[0])dp[i][0]=1;
     if(dp[i][2])return true;
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;gen(s);cin>>s;
   //cal(s,"022");exit(0);
  int ans=0;
  for(auto x:v)ans+=cal(s,x);
  cout<<ans<<endl;
    return 0;
}