/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/14/2019 15:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 3244 ms                                         memory_used: 317100 KB                            
*  problem: https://codeforces.com/contest/434/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
const long mod=1e9+7;
int n,k,dp[N+1][N+1][501][2][2],opt[N+2];
vector<int>lo,hi,nm[N+2];
/************* Aho Corasick ***************/
const int A=2e2;
int W,Nw;
struct Aho_Corasick
{
  int next[20+1],link,f;
}Trie[A+2];
void Aho_Insrt(vector<int>s,int vl)
{
  int now=0;
  for(int i=0;i<s.size();i++)
  {
    int c=s[i];
    if(!Trie[now].next[c])Trie[now].next[c]=++Nw;
    now=Trie[now].next[c];
  }
  Trie[now].f+=vl;
}
void Aho(void)
{
  queue<int>q;q.push(0);
  while(q.size())
  {
    int u=q.front();q.pop();
    int v=Trie[u].link;
    for(int c=0;c<W;c++)
    {
      int nx=Trie[u].next[c];
      if(nx)
      {
        q.push(nx);if(!u)Trie[nx].link=0;
        else Trie[nx].link=Trie[v].next[c];
      }
      else Trie[u].next[c]=Trie[v].next[c];
    }
  }
}
////////////////////////////////////////////
int cal(int now)
{
  if(opt[now]!=-1)return opt[now];
  int ret=0,nnn=now;
  while(now)
  {
    ret+=Trie[now].f;
    now=Trie[now].link;
  }
  return opt[nnn]=ret;
}
vector<int>aa;
long dfs(int st,int now,int kk,int ck,int f)
{
  if(kk>k)return 0;if(st>=aa.size())return f;
  long cnt=0;
  if(dp[st][now][kk][ck][f]!=-1)return dp[st][now][kk][ck][f];
  for(int c=0;c<W;c++)
  {
    int nx=Trie[now].next[c];
    int ex=cal(nx);
    if(ck)
    {
      if(c>aa[st])continue;
      if(c==aa[st])
      {
        cnt=(cnt+dfs(st+1,nx,kk+ex,1,1))%mod;
        continue;
      }
      if(c)cnt=(cnt+dfs(st+1,nx,kk+ex,0,1))%mod;
      else
      {
        if(!f)cnt=(cnt+dfs(st+1,0,kk,0,0))%mod;
        else cnt=(cnt+dfs(st+1,nx,kk+ex,0,1))%mod;
      }
    }
    else
    {
      if(c)cnt=(cnt+dfs(st+1,nx,kk+ex,0,1))%mod;
      else
      {
        if(!f)cnt=(cnt+dfs(st+1,0,kk,0,0))%mod;
        else cnt=(cnt+dfs(st+1,nx,kk+ex,0,1))%mod;
      }
    }
  }
  return dp[st][now][kk][ck][f]=cnt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>W>>k;int x;cin>>x;
  while(x--){int z;cin>>z;lo.push_back(z);}
  cin>>x;while(x--){int z;cin>>z;hi.push_back(z);}
  for(int i=1;i<=n;i++)
  {
    vector<int>v;cin>>x;
    while(x--){int z;cin>>z;v.push_back(z);}
    int vl;cin>>vl;Aho_Insrt(v,vl);
  }
  Aho();memset(opt,-1,sizeof(opt));
  aa=hi;long one,two;memset(dp,-1,sizeof(dp));
  two=dfs(0,0,0,1,0);memset(dp,-1,sizeof(dp));
  aa=lo;one=dfs(0,0,0,1,0);
  long df=(two-one+mod)%mod;
   int now=0;
  for(auto x:lo)
  {
    now=Trie[now].next[x];
    k-=cal(now);
  }
  if(k>=0)df=(df+1)%mod;
  cout<<df<<endl;
  return 0;
}