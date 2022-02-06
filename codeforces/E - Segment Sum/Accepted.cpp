/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/26/2018 00:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 5700 KB                              
*  problem: https://codeforces.com/contest/1073/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
const long mod=998244353;
long k,n,aa[22];
long pw[22];
pair<long,long>dp[22][1<<12][2][2];
pair<long,long>dfs(long st,long msk,long f,long ck)
{
  if(st>n)
  {
    if(__builtin_popcount(msk)<=k)return {1,0};
    else return {0,0};
  }
  if(dp[st][msk][f][ck].first!=-1)return dp[st][msk][f][ck];
  long here=0,cnt=0;long tmp=msk;
  if(!ck)
  {
    for(long i=0;i<=9;i++)
    {
      if(i==0)
      {
        if(f)tmp=msk|(1<<i);
        pair<long,long>nw=dfs(st+1,tmp,f,0);
        cnt=(cnt+nw.first)%mod;
        here=(here+i*pw[n-st]*nw.first+nw.second)%mod;
      }
      else
      {
        tmp=msk|(1<<i);
        pair<long,long>nw=dfs(st+1,tmp,1,0);
        cnt=(cnt+nw.first)%mod;
        here=(here+i*pw[n-st]*nw.first+nw.second)%mod;
      }
    }
  }
  else
  {
    for(long i=0;i<=aa[st];i++)
    {
      if(i==aa[st])
      {
        tmp=msk|(1<<i);
        pair<long,long>nw=dfs(st+1,tmp,1,1);
        cnt=(cnt+nw.first)%mod;
        here=(here+i*pw[n-st]*nw.first+nw.second)%mod;
      }
      else if(i==0)
      {
        if(f)tmp=msk|(1<<i);
        pair<long,long>nw=dfs(st+1,tmp,f,0);
        cnt=(cnt+nw.first)%mod;
        here=(here+i*pw[n-st]*nw.first+nw.second)%mod;
      }
      else
      {
        tmp=msk|(1<<i);
        pair<long,long>nw=dfs(st+1,tmp,1,0);
        cnt=(cnt+nw.first)%mod;
        here=(here+i*pw[n-st]*nw.first+nw.second)%mod;
      }
    }
  }
  return dp[st][msk][f][ck]={cnt,here};
}
void convert(long x)
{
  vector<long>v;
  while(x)
  {
    v.push_back(x%10);x/=10;
  }
  reverse(v.begin(),v.end());
  n=v.size();
  for(long i=1;i<=n;i++)
    aa[i]=v[i-1];
}
void mem(void)
{
  for(long i=0;i<22;i++)
  {
    for(long j=0;j<(1<<12);j++)
    {
      for(long k=0;k<2;k++)
      {
        for(long l=0;l<2;l++)
        {
          dp[i][j][k][l]={-1,-1};
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;for(long i=1;i<=20;i++)pw[i]=(pw[i-1]*10LL)%mod;
  long lt,rt;cin>>lt>>rt>>k;
  convert(rt);mem();
  long one=dfs(1,0,0,1).second;
  lt--;convert(lt);mem();
  cout<<(one-dfs(1,0,0,1).second+mod)%mod<<endl;
   return 0;
}