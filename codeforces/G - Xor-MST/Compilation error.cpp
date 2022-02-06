/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2019 00:13                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/888/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int sz,par[N+2];
struct data
{
  int next[2],cnt,id;
}trie[N+2];
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
void add(int x,int id)
{
  for(int i=29;i>=0;i--)
  {
    bool b=(x&(1<<i));
    if(!trie[now].next[b])trie[now].next[b]=++sz;
    now=trie[now].next[b];trie[now].cnt++;
  }
  trie[now].id=i;
}
void rem(int x)
{
  for(int i=29;i>=0;i--)
  {
    bool b=(x&(1<<i));
    now=trie[now].next[b];trie[now].cnt--;
  }
}
void find(int x)
{
 }
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  sort(v.begin(),v.end());
   v.erase(unique(v.begin(),v.end()),v.end());
   n=v.size();for(int i=0;i<n;i++)par[i]=i;
     return 0;
}