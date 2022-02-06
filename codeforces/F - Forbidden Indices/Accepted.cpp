/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/25/2019 23:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 52500 KB                             
*  problem: https://codeforces.com/contest/873/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
struct automata
{
  int len,link,next[26];
}aut[N+N+2];
int sz,last,occur[N+N+2];
void init(void)
{
  aut[0].link=-1;
}
void add(int c,int f)
{
  int now=++sz;aut[now].len=aut[last].len+1;
  int p,q,cl;occur[now]=!f;
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
      aut[cl].link=aut[q].link;
      memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
      for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
        aut[p].next[c]=cl;
      aut[now].link=aut[q].link=cl;
    }
  }
  last=now;
}
void occurrences(int n)
{
  vector<vector<int> >vLen(n+2);
  for(int i=1;i<=sz;i++)
    vLen[aut[i].len].push_back(i);
  for(int i=n;i>=1;i--)
    for(auto x:vLen[i])
      occur[aut[x].link]+=occur[x];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string a,b;cin>>a>>b;init();
  for(int i=0;i<n;i++)add(a[i]-'a',b[i]-'0');
  occurrences(n);
   long ans=0;
  for(int i=1;i<=sz;i++)
    ans=max(ans,1LL*aut[i].len*occur[i]);
  cout<<ans<<endl;
   return 0;
}