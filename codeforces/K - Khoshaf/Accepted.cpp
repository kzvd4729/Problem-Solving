/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/31/2019 00:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 3837 ms                                         memory_used: 105700 KB                            
*  problem: https://codeforces.com/gym/101991/problem/K
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,k,l,r,zr,on,tw;
const int mod=1e9+7;
int dp[422][146][146][3];
int ret(int l,int r,int a)
{
  while(l%3!=a)l++;
  if(l>r)return 0;
  return (r-l)/3+1;
}
int dfs(int id,int a,int b,int ls)
{
  int c=id-a-b;
  if((a*(a-1)/2)+(b*(b-1)/2)+(c*(c-1)/2)>k)return 0;
   if(id>n)
  {
    if((a*(a-1)/2)+(b*(b-1)/2)+(c*(c-1)/2)==k)return 1;
    return 0;
  }
  if(dp[id][a][b][ls]!=-1)return dp[id][a][b][ls];
   int now=0;
   //0 case
  if(ls==0)now=now+(1LL*zr*dfs(id+1,a+1,b,ls))%mod;
  if(now>=mod)now-=mod;
   if(ls==1)now=now+(1LL*zr*dfs(id+1,a,b+1,ls))%mod;
  if(now>=mod)now-=mod;
   if(ls==2)now=now+(1LL*zr*dfs(id+1,a,b,ls))%mod;
  if(now>=mod)now-=mod;
    //1
  if(ls==0)now=now+(1LL*on*dfs(id+1,a,b+1,1))%mod;
  if(now>=mod)now-=mod;
   if(ls==1)now=now+(1LL*on*dfs(id+1,a,b,2))%mod;
  if(now>=mod)now-=mod;
   if(ls==2)now=now+(1LL*on*dfs(id+1,a+1,b,0))%mod;
  if(now>=mod)now-=mod;
   //2
  if(ls==0)now=now+(1LL*tw*dfs(id+1,a,b,2))%mod;
  if(now>=mod)now-=mod;
   if(ls==1)now=now+(1LL*tw*dfs(id+1,a+1,b,0))%mod;
  if(now>=mod)now-=mod;
   if(ls==2)now=now+(1LL*tw*dfs(id+1,a,b+1,1))%mod;
  if(now>=mod)now-=mod;
   return dp[id][a][b][ls]=now;
}
int main()
{
  freopen("khoshaf.in","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>k>>l>>r;
    if(n>420)
    {
      cout<<0<<endl;continue;
    }
    zr=ret(l,r,0),on=ret(l,r,1),tw=ret(l,r,2);
    //cout<<zr<<" "<<on<<" "<<tw<<endl;
    memset(dp,-1,sizeof(dp));
    cout<<dfs(1,1,0,0)<<"\n";
  }
  return 0;
}