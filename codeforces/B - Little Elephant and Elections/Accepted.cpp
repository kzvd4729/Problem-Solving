/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2020 11:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/258/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
vector<int>v;
void abc(int n)
{
  while(n)
  {
    v.push_back(n%10);
    n/=10;
  }
  reverse(v.begin(),v.end());
}
int dp[10+2][2+2][10+2];
int dfs(int i,int c,int l)
{
  if(l<0)return 0;
  if(i==v.size())return !((bool)l);
  if(dp[i][c][l]!=-1)return dp[i][c][l];
  int ret=0;
  if(c==0)
  {
    for(int d=0;d<=9;d++)
      ret+=dfs(i+1,0,l-(d==4||d==7));
  }
  else
  {
    for(int d=0;d<v[i];d++)
      ret+=dfs(i+1,0,l-(d==4||d==7));
    ret+=dfs(i+1,1,l-(v[i]==4||v[i]==7));
  }
  return dp[i][c][l]=ret;
}
int cnt[10+2];
int ans;
int npr(int n,int r)
{
  int ret=1;
  for(int i=n-r+1;i<=n;i++)ret=(1LL*ret*i)%mod;
  return ret;
}
int ncr(int n,int r)
{
  int ret=npr(n,r);
  for(int i=2;i<=r;i++)ret/=i;
  return ret;
}
void cal(vector<int>v)
{
  int mx=0,ad=0;
  for(int i=9;i>=0;i--)
  {
    if(v[i]){mx=i;break;}
  }
  if(v[mx]>1)return ;
  for(int i=0;i<mx;i++)ad+=i*v[i];
  if(ad>=mx)return ;
  //for(int i=0;i<10;i++)cout<<v[i]<<" ";cout<<endl;
   int now=cnt[mx],rm=6;
  for(int i=0;i<mx;i++)
  {
    now=(1LL*now*(1LL*ncr(rm,v[i])*npr(cnt[i],v[i]))%mod)%mod;
    rm-=v[i];
  }
  ans=(ans+now)%mod;
}
void dfs(int i,int n,vector<int>v)
{
  if(i==0)
  {
    if(n)return ;
    cal(v);return ;
  }
  for(int j=0;j<=n;j++)
  {
    v.push_back(j);
    dfs(i-1,n-j,v);v.pop_back();
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;abc(n);
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<=9;i++)
    cnt[i]=dfs(0,1,i);
  cnt[0]--;
  vector<int>u;dfs(10,7,u);
  cout<<ans<<endl;
  return 0;
}