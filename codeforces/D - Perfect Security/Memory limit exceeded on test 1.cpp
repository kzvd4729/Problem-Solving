/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2018 13:51                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++17                               
*  run_time: 0 ms                                            memory_used: 524300 KB                            
*  problem: https://codeforces.com/contest/948/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e5;
long trie[32*N+2][4],now,cnt[32*N+2][4],n,x,arr[N+2],sz;
bool k;
void insrt(long x,long f)
{
  now=0;
  for(long i=30;i>=0;i--)
  {
    k=x&(1<<i);
    if(f==1)cnt[now][k]++;
    if(f==-1)cnt[now][k]--;
    if(!trie[now][k])trie[now][k]=++sz;
    now=trie[now][k];
  }
}
long query(long x)
{
  now=0;
  long ans=0;
  for(long i=30;i>=0;i--)
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=1;i<=n;i++)
    {
      cin>>x;
      insrt(x,1);
    }
    for(long i=1;i<=n;i++)
    {
      x=arr[i];
      long xx=query(x);
      long tmp=xx^x;
      cout<<tmp<<" ";
      insrt(xx,-1);
    }
    cout<<endl;
    return 0;
}