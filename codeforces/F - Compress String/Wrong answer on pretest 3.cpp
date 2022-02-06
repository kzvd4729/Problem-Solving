/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2019 22:37                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/1121/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
/***************** Automata **********************/
const int A=5e3;
int Sz,Last;
struct Automata
{
  int len,link,next[26];
}aut[A+A+2];
void Insrt(int c)
{
  int now=++Sz;aut[now].len=aut[Last].len+1;
  int p,q,cl;
  for(p=Last;p!=-1&&!aut[p].next[c];p=aut[p].link)
    aut[p].next[c]=now;
  if(p==-1)
    aut[now].link=0;
  else
  {
    q=aut[p].next[c];
    if(aut[p].len+1==aut[q].len)
      aut[now].link=q;
    else
    {
      cl=++Sz;aut[cl].len=aut[p].len+1;
      aut[cl].link=aut[q].link;
      memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
      for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
        aut[p].next[c]=cl;
      aut[now].link=aut[q].link=cl;
    }
  }
  Last=now;
}
//////////////////////////////////////////////
int n,a,b,nex[N+N+2],dp[N+2];
string s;
int dfs(int i)
{
  if(i>=n)return 0;
  if(dp[i]!=-1)return dp[i];
  int now=1e9;
  now=min(now,a+dfs(i+1));
  if(nex[i]>i)now=min(now,b+dfs(nex[i]));
  return dp[i]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>a>>b;aut[0].link=-1;cin>>s;s.push_back('#');
   for(int i=0;i<n;i++)
  {
    int now=0;
    for(int j=i;j<=n;j++)
    {
      int c=s[j]-'a';
      if(aut[now].next[c])
        now=aut[now].next[c];
      else 
      {
        nex[i]=j;break;
      }
    }
    Insrt(s[i]-'a');
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0)<<endl;
  return 0;
}