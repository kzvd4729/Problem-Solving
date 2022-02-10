/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-17 11:32:32                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1394
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,st,ed,mo,nm,kk;
long dp[33][3][33][33][4][8];
vector<int>now,num;
vector<int>make_binary(int x)
{
  vector<int>ret;
  for(int i=30;i>=0;i--)
    ret.push_back(bool(x&(1<<i)));
  return ret;
}
long dfs(int id,int ck,int mm,int pop,int xx)
{
  if(id==31)
  {
    if(mm<=kk&&pop<=mo&&xx%3==0&&xx%7)return xx*1LL;
    else return 0LL;
  }
  if(dp[id][ck][mm][pop][xx%3][xx%7]!=-1)return dp[id][ck][mm][pop][xx%3][xx%7];
  long cnt=0;
  if(now[id]==0)
  {
    if(ck==1)
      cnt+=dfs(id+1,ck,mm+(num[id]!=0),pop,xx*2);
    else
    {
      cnt+=dfs(id+1,ck,mm+(num[id]!=0),pop,xx*2);
      cnt+=dfs(id+1,ck,mm+(num[id]!=1),pop+1,xx*2+1);
    }
  }
  else
  {
    if(ck==1)
    {
      cnt+=dfs(id+1,0,mm+(num[id]!=0),pop,xx*2);
      cnt+=dfs(id+1,1,mm+(num[id]!=1),pop+1,xx*2+1);
    }
    else
    {
      cnt+=dfs(id+1,ck,mm+(num[id]!=0),pop,xx*2);
      cnt+=dfs(id+1,ck,mm+(num[id]!=1),pop+1,xx*2+1);
    }
  }
  return dp[id][ck][mm][pop][xx%3][xx%7]=cnt;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    now.clear();
    num.clear();
    scanf("%d%d%d%d%d",&st,&ed,&mo,&nm,&kk);
    now=make_binary(ed);
    num=make_binary(nm);
    memset(dp,-1,sizeof(dp));
    long tmp=dfs(0,1,0,0,0);
    now.clear();
    now=make_binary(st-1);
    memset(dp,-1,sizeof(dp));
    long tmp2=dfs(0,1,0,0,0);
    printf("Case %d: %lld\n",++tc,tmp-tmp2);

  }
  return 0;
}