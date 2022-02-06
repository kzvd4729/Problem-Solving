/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2020 20:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2823 ms                                         memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/1172/problem/C1
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define endl '\n'
#define long long long  
using namespace std;
const int N=50;
const int mod=998244353;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int n,m,a[N+2],b[N+2],sm,rm[200000+2];
int my,pst,ngt,f,dst,dp[N+2][N+2][N+2];
int inv(int x)
{
  int c=sm-x+100000;
  if(rm[c]!=-1)return rm[c];
   return rm[c]=big(x,mod-2);
}
int dfs(int mv,int sl,int ps)
{
  if(mv==m)return sl==dst;
  if(dp[mv][sl][ps]!=-1)return dp[mv][sl][ps];
  int myw=my+sl*f;
  int psw=pst+ps;
  int ngw=ngt-(mv-(sl+ps));
  //if(myw<0||ngw<0)return 0;
  //cout<<myw<<" "<<psw<<" "<<ngw<<endl;
  int tt=inv(myw+psw+ngw);
   int ret=0;
  ret=(ret+(1LL*tt*myw)%mod*dfs(mv+1,sl+1,ps))%mod;
  ret=(ret+(1LL*tt*psw)%mod*dfs(mv+1,sl,ps+1))%mod;
  ret=(ret+(1LL*tt*ngw)%mod*dfs(mv+1,sl,ps))%mod;
   return dp[mv][sl][ps]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)
  {
    cin>>b[i];sm+=b[i];
    if(a[i])pst+=b[i];else ngt+=b[i];
  }
  memset(rm,-1,sizeof rm);
  for(int i=1;i<=n;i++)
  {
    my=b[i];f=1;if(a[i]==0)f=-1;
    if(f==1)pst-=my;else ngt-=my;
    int ans=0;
    for(dst=0;dst<=m;dst++)
    {
      //cout<<"**"<<dfs(0,0,0)<<endl;
      memset(dp,-1,sizeof dp);
      ans=(ans+1LL*(my+dst*f)*dfs(0,0,0))%mod;
    }
    cout<<ans<<endl;
    if(f==1)pst+=my;else ngt+=my;
  }
  return 0;
}