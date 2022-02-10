/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-22 15:51:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 496                                        memory_used (MB): 36.8                            
*  problem: https://vjudge.net/problem/LightOJ-1269
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,trie[90*50000][2],sz,t,tc;
void insrt(int x)
{
  int now=0;
  for(int i=31;i>=0;i--)
  {
    bool z=x&(1<<i);
    if(!trie[now][z])trie[now][z]=++sz;
    now=trie[now][z];
  }
}
int max_query(int x)
{
  int now=0,ret=0;
  for(int i=31;i>=0;i--)
  {
    bool z=x&(1<<i);
    if(trie[now][z^1])
    {
      ret+=(1<<i);
      now=trie[now][z^1];
    }
    else now=trie[now][z];
  }
  return ret;
}
int min_query(int x)
{
  int now=0,ret=0;
  for(int i=31;i>=0;i--)
  {
    bool z=x&(1<<i);
    if(trie[now][z])now=trie[now][z];
    else
    {
      ret+=(1<<i);
      now=trie[now][z^1];
    }
  }
  return ret;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    memset(trie,0,sizeof(trie));

    scanf("%d",&n);
    int xxr=0,x,mx=0,mn=INT_MAX;
    insrt(0);
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&x);
      xxr=xxr^x;
      mx=max(mx,max_query(xxr));
      mn=min(mn,min_query(xxr));
      insrt(xxr);
    }
    printf("Case %d: %d %d\n",++tc,mx,mn);
  }
  return 0;
}