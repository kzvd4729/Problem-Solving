/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2019 19:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 4500 KB                              
*  problem: https://codeforces.com/contest/6/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,a,b,aa[N+2],dp[20][20][20][20];
int dfs(int st,int lt,int md,int rt)
{
  lt=max(lt,0);rt=max(rt,0);md=max(md,0);
  if(st==n-1&&!lt&&!md&&!rt)return dp[st][lt][md][rt]=0;
  if(dp[st][lt][md][rt]!=-1)return dp[st][lt][md][rt];
  int here=1e9;
  if(lt||md||rt)
    here=min(here,1+dfs(st,lt-b,md-a,rt-b));
  if(!lt&&st<n-1)
    here=min(here,dfs(st+1,md,rt,aa[st+2]));
  return dp[st][lt][md][rt]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>a>>b;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];aa[i]++;
  }
  memset(dp,-1,sizeof(dp));
  int pr=dfs(2,aa[1],aa[2],aa[3]);
  cout<<pr<<endl;
   int st=2,lt=aa[1],md=aa[2],rt=aa[3];
  vector<int>ans;
  while(true)
  {
    //cout<<st<<" "<<lt<<" "<<md<<" "<<rt<<endl;
    if(st==n-1&&!lt&&!md&&!rt)break;
    int f=0;
    if(lt||md||rt)
    {
      int l=max(0,lt-b);
      int m=max(0,md-a);
      int r=max(0,rt-b);
      if(dp[st][l][m][r]+1==dp[st][lt][md][rt])
      {
        ans.push_back(st);
        lt=l,rt=r,md=m;
        f=1;
      }
    }
    if(f==0)
    {
      if(!lt&&st<n-1)
      {
        if(dp[st+1][md][rt][aa[st+2]]==dp[st][lt][md][rt])
        {
          st++;
          int a=md,b=rt,c=aa[st+1];
          lt=a,md=b,rt=c;
        }
      }
    }
  }
  if(ans.size()!=pr)assert(0);
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}