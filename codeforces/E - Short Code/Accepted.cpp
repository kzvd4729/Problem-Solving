/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2020 13:52                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 24400 KB                             
*  problem: https://codeforces.com/contest/965/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#define long long long 
using namespace std;
const int N=1e5;
struct node
{
  int next[26];
}trie[N+2];
int nw,f[N+2];
void insrt(string s)
{
  int now=0,n=s.size();
  for(int i=0;i<n;i++)
  {
    int c=s[i]-'a';
    if(!trie[now].next[c])trie[now].next[c]=++nw;
    now=trie[now].next[c];
  }
  f[now]=1;
}
vector<int>ad[N+2];priority_queue<int>pq[N+2];
int dfs(int nd,int d)
{
  vector<int>v;
  for(auto x:ad[nd])
    v.push_back(dfs(x,d+1));
  if(ad[nd].size()==0)
  {
    assert(f[nd]);
    pq[nd].push(d);return nd;
  }
  int mx=-1,bg;
  for(auto x:v)
  {
    if((int)pq[x].size()>mx)mx=pq[x].size(),bg=x;
  }
  for(auto x:v)
  {
    if(x==bg)continue;
    while(pq[x].size())
    {
      pq[bg].push(pq[x].top());pq[x].pop();
    }
  }
  pq[bg].push(d);if(!f[nd])pq[bg].pop();
  return bg;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;insrt(s);
  }
  for(int i=0;i<=nw;i++)
  {
    for(int c=0;c<26;c++)
      if(trie[i].next[c])ad[i].push_back(trie[i].next[c]);
  }
  f[0]=1;int id=dfs(0,0);
  long ans=0;while(pq[id].size()){ans+=pq[id].top();pq[id].pop();}
  cout<<ans<<endl;
  return 0;
}