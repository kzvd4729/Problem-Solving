/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-14 12:24:07                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1427
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500*500;
int ind[N+2],ans[N+2];
/************* Aho Corasick ***************/
const int W=26,A=500*500;
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
    int c=s[i]-'a';
    if(!Trie[now].next[c])Trie[now].next[c]=++Nw;
    now=Trie[now].next[c];
  }
  Trie[now].f=id;
}
void Aho_Build(void)
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
int Count(int n)
{
  for(int i=0;i<Frw[n].size();i++)
    Occur[n]+=Count(Frw[n][i]);
  return ans[Trie[n].f]=Occur[n];
}
void AC(string s)
{
  for(int i=1;i<=Nw;i++)
    Frw[Trie[i].link].push_back(i);
  int now=0;
  for(int i=0;s[i];i++)
  {
    int c=s[i]-'a';
    now=Trie[now].next[c];
    Occur[now]++;
  }
  Count(0);
}
////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
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
    memset(ans,0,sizeof(ans));
    int n;cin>>n;string tx;cin>>tx;
    for(int i=1;i<=n;i++)
    {
      string s;cin>>s;
      if(mp[s])ind[i]=mp[s];
      else mp[s]=i,Aho_Insrt(s,i);
    }
    Aho_Build();AC(tx);
    cout<<"Case "<<++tc<<":"<<"\n";
    for(int i=1;i<=n;i++)
    {
      if(!ind[i])cout<<ans[i]<<"\n";
      else cout<<ans[ind[i]]<<"\n";
    }
  }
  return 0;
}