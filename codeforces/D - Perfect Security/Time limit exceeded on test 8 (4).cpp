/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2018 13:45                        
*  solution_verdict: Time limit exceeded on test 8           language: GNU C++17                               
*  run_time: 3500 ms                                         memory_used: 102400 KB                            
*  problem: https://codeforces.com/contest/948/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int trie[32*N+2][4],now,cnt[32*N+2][4],n,x,arr[N+2],sz;
bool k;
void insrt(int x,int f)
{
  now=0;
  for(int i=30;i>=0;i--)
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
  for(int i=30;i>=0;i--)
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
    cout.tie(0);
     cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      insrt(x,1);
    }
    for(int i=1;i<=n;i++)
    {
      x=arr[i];
      int xx=query(x);
      int tmp=xx^x;
      cout<<tmp<<" ";
      insrt(xx,-1);
    }
    cout<<endl;
    return 0;
}