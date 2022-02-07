/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-14 13:41:24                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 490                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10679
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ind[N+2],ans[N+2];
int con(char c)
{
  if(c>='a'&&c<='z')return c-'a';
  return c-'A'+26;
}
/************* Aho Corasick ***************/
const int W=52,A=1e6;
int Nw,Occur[A+2];
vector<int>Frw[A+2];
struct Aho_Corasick
{
  int next[W+1],link,f;
}Trie[A+2];
void Aho_Insrt(string s,int id)
{
  int now=0;
  for(int i=0;s[i];i++)
  {
    int c=con(s[i]);
    if(!Trie[now].next[c])Trie[now].next[c]=++Nw;
    now=Trie[now].next[c];
  }
  Trie[now].f=id;
}
int Count(int n)
{
  for(int i=0;i<Frw[n].size();i++)
    Occur[n]+=Count(Frw[n][i]);
  return Occur[n];
}
void Aho(string s)
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
  for(int i=1;i<=Nw;i++)
    Frw[Trie[i].link].push_back(i);
  int now=0;
  for(int i=0;s[i];i++)
  {
    int c=con(s[i]);
    now=Trie[now].next[c];
    Occur[now]++;
  }
  Count(0);
}
////////////////////////////////////////////
void out(int x)
{
  if(x)cout<<"y\n";
  else cout<<"n\n";
}
int main()
{
  int t,tc=0;cin>>t;
  while(t--)
  {
    for(int i=0;i<=N;i++)
    {
      memset(Trie[i].next,0,sizeof(Trie[i].next));
      Trie[i].f=0,Trie[i].link=0;
      Frw[i].clear();Occur[i]=0;
    }Nw=0;map<string,int>mp;
    memset(ind,0,sizeof(ind));
    string tx;cin>>tx;int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      string s;cin>>s;
      if(mp[s])ind[i]=mp[s];
      else mp[s]=i,Aho_Insrt(s,i);
    }
    Aho(tx);for(int i=1;i<=Nw;i++)ans[Trie[i].f]=Occur[i];
    for(int i=1;i<=n;i++)
    {
      if(!ind[i])out(ans[i]);
      else out(ans[ind[i]]);
    }
  }
  return 0;
}