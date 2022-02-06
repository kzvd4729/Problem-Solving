/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2018 13:50                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 514 ms                                          memory_used: 303600 KB                            
*  problem: https://codeforces.com/contest/948/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int trie[32*N+2][4],now,cnt[32*N+2][4],n,x,arr[N+2],sz,xx,tmp;
bool k;
void insrt(int x,int f)
{
  now=0;
  for(int i=29;i>=0;i--)
  {
    k=x&(1<<i);
    if(f==1)cnt[now][k]++;
    if(f==-1)cnt[now][k]--;
    if(!trie[now][k])trie[now][k]=++sz;
    now=trie[now][k];
  }
}
int query(int x)
{
  now=0;
  int ans=0;
  for(int i=29;i>=0;i--)
  {
    k=x&(1<<i);
    if(cnt[now][k])
    {
      if(k)ans|=(1<<i);
      now=trie[now][k];
    }
    else
    {
      k=k^1;
      if(k)ans|=(1<<i);
      now=trie[now][k];
    }
  }
  return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&x);
      insrt(x,1);
    }
    for(int i=1;i<=n;i++)
    {
      x=arr[i];
      xx=query(x);
      tmp=xx^x;
      printf("%d\n",tmp);
      insrt(xx,-1);
    }
    printf("\n");
    return 0;
}