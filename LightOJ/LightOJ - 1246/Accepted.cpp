/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-23 19:22:38                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1743                                       memory_used (MB): 14.5                            
*  problem: https://vjudge.net/problem/LightOJ-1246
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,mod=1e9+7;
int on,tw,dp[50+2][204][204];

int ncr[1000+2][1000+2];
void calNCR(int n)
{
  for(int i=1;i<=n;i++)ncr[i][0]=1;
  ncr[1][1]=1;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
  }
}

int dfs(int k,int a,int b)
{
  if(k==0)
  {
    if(a|b)return 0;return 1;
  }
  if(a>b)swap(a,b);
  if(dp[k][a][b]!=-1)return dp[k][a][b];
  long now=dfs(k-1,a,b);
  for(int i=1;i<=a;i++)
    now=(now+1LL*ncr[a][i]*dfs(k-1,a-i,b))%mod;
  for(int i=1;i<=b;i++)
    now=(now+1LL*ncr[b][i]*dfs(k-1,a,b-i))%mod;
  return dp[k][a][b]=now;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;calNCR(300);memset(dp,-1,sizeof(dp));
  while(t--)
  {
    int a,b,c;scanf("%d%d%d",&a,&b,&c);a++,b++;
    int on=(a*b)/2;int tw=a*b-on;
    printf("Case %d: %d\n",++tc,dfs(c,on,tw));
    //cout<<"Case "<<++tc<<": "<<dfs(c,on,tw)<<"\n";
  }
  return 0;
}