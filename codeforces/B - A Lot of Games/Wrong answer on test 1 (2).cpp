/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/02/2018 18:44                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/455/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int trie[N+2][27],nw,win[N+2],los[N+2];
void insrt(string s)
{
  int now=0;
  for(auto x:s)
  {
    int c=x-'a';
    if(!trie[now][c])trie[now][c]=++nw;
    now=trie[now][c];
  }
}
void dfs(int now)
{
  int f=0;
  for(int i=0;i<26;i++)
  {
    if(trie[now][i])
    {
      dfs(trie[now][i]);f=1;
      win[now]|=los[trie[now][i]];
      los[now]|=win[trie[now][i]];
    }
  }
  if(!f)win[now]=0,los[now]=1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;insrt(s);
  }
  dfs(0);cout<<win[0]<<" "<<los[0]<<endl;
  if(!win[0]||(!los[0]&&k%2==0))cout<<"Second"<<endl;
  else cout<<"First"<<endl;
  return 0;
}