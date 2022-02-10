/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-13 17:30:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 392                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-3942
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,in=26;
const long mod=20071027;
int n,nw,tr[N+2][27];
long dp[N+2];
string s;
void add(string s)
{
  int now=0;
  for(auto x:s)
  {
    int c=x-'a';
    if(!tr[now][c])tr[now][c]=++nw;
    now=tr[now][c];
  }
  tr[now][in]=1;
}
long dfs(int st)
{
  if(st>=s.size())return 1;
  if(dp[st]!=-1)return dp[st];
  int now=0;long here=0;
  for(int i=st;i<s.size();i++)
  {
    int c=s[i]-'a';now=tr[now][c];
    if(!now)break;
    if(tr[now][in])here=(here+dfs(st+(i-st+1)))%mod;
  }
  return dp[st]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int tc=0;
  while(cin>>s)
  {
    cin>>n;nw=0;memset(tr,0,sizeof(tr));
    for(int i=1;i<=n;i++)
    {
      string x;cin>>x;add(x);
    }
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<++tc<<": "<<dfs(0)<<endl;
  }
  return 0;
}