/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-04 17:23:25                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-4682
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int trie[70*N+2][3],sz;
void add(int x)
{
  int now=0;
  for(int i=30;i>=0;i--)
  {
    bool z=x&(1<<i);
    if(!trie[now][z])trie[now][z]=++sz;
    now=trie[now][z];
  }
}
int query(int x)
{
  int now=0,ret=0;
  for(int i=30;i>=0;i--)
  {
    bool z=x&(1<<i);
    if(trie[now][z^1])
    {
      ret|=(1<<i);
      now=trie[now][z^1];
    }
    else now=trie[now][z];
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    memset(trie,0,sizeof(trie));sz=0;add(0);
    int n,xxr=0,ans=0;cin>>n;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      ans=max(ans,query(x));
      xxr^=x;add(xxr);
    }
    cout<<ans<<endl;
  }
  return 0;
}