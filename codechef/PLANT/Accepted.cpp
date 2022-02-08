/****************************************************************************************
*  @author: kzvd4729                                         created: 30-11-2019 20:57:21                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.66 sec                                        memory_used: 703.5M                               
*  problem: https://www.codechef.com/LTIME78A/problems/PLANT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6,inf=1e9;
struct automata
{
  int len,link,next[26];
}aut[N+N+2];
int sz,last,occur[N+N+2],firstP[N+N+2],lastP[N+N+2];
void init(void)
{
  aut[0].link=-1;
}
void insrt(int c)
{
  int now=++sz;aut[now].len=aut[last].len+1;
  firstP[now]=aut[now].len-1;lastP[now]=aut[now].len-1;
  int p,q,cl;occur[now]=1;
  for(p=last;p!=-1&&!aut[p].next[c];p=aut[p].link)
    aut[p].next[c]=now;
  if(p==-1)aut[now].link=0;
  else
  {
    q=aut[p].next[c];
    if(aut[p].len+1==aut[q].len)aut[now].link=q;
    else
    {
      cl=++sz;aut[cl].len=aut[p].len+1;
      aut[cl].link=aut[q].link;firstP[cl]=firstP[q];
      memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
      for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
        aut[p].next[c]=cl;
      aut[now].link=aut[q].link=cl;
    }
  }
  last=now;
}
vector<int>adj[N+N+2];
void dfs(int node)
{
  for(auto x:adj[node])
  {
    dfs(x);lastP[node]=max(lastP[node],lastP[x]);
  }
}
void makeTree(void)
{
  for(int i=1;i<=sz;i++)
    adj[aut[i].link].push_back(i);
  dfs(0);
}
void occurences(int n)//n=string size;
{
  vector<vector<int> >vLen(n+2);
  for(int i=1;i<=sz;i++)
    vLen[aut[i].len].push_back(i);
  for(int i=n;i>=1;i--)
    for(auto x:vLen[i])
      occur[aut[x].link]+=occur[x];
}
int ret(string s)
{
  int now=0;
  for(auto x:s)
    now=aut[now].next[x-'a'];
  return now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  string s;cin>>s;init();
  for(auto x:s)insrt(x-'a');
  makeTree();occurences(n);
    long ans=0;
  for(int i=1;i<=sz;i++)
  {
    if(occur[i]<2)continue;
    int ln=aut[i].len;
    if(firstP[i]<lastP[i]-ln+1)
    {
      ans=max(ans,1LL*ln*(n-firstP[i]-1));
      ans=max(ans,1LL*ln*(lastP[i]-ln+1));
    }
  }
  cout<<ans<<endl;
  return 0;
}