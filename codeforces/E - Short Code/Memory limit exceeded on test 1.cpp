/****************************************************************************************
*  @author: kzvd4729                                         created: May/03/2018 01:42                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/965/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,sz;
long ans;
string s;
struct tree
{
  int len;
  int next[26];
}trie[3000000];
void insrt()
{
  int now=0,l=0;
  for(auto x:s)
  {
    int c=x-'a';
    if(!trie[now].next[c])trie[now].next[c]=++sz;
    trie[now].len=++l;
    now=trie[now].next[c];
  }
}
void bfs(void)
{
  queue<int>q;
  q.push(0);
  while(q.size())
  {
    int u=q.front();
    q.pop();
    for(int i=0;i<26;i++)
    {
      if(trie[u].next[i]&&n)
      {
        n--;
        ans+=(trie[u].len)*1LL;
        q.push(trie[u].next[i]);
      }
    }
  }
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    insrt();
  }
  bfs();
  return 0;
}