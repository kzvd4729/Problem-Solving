/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/03/2019 19:43                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/204/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
 /*
to insert one more string make sam.last=0 before every string insertion.
if(aut[aut[i].link].len<aut[i].len)then state i is unique.
sort the suffix with their dfs timing order in prefix tree
*/
struct suffixAutomata
{
  int sz,last,occur[N+N+2];
  vector<int>tree[N+N+2];
  struct node
  {
    int len,link,next[26];
  }aut[N+N+2];//2*insrt function call
  void clean(int n=N)//must call before insert
  {
    for(int i=0;i<=n+n;i++)
    {
      memset(aut[i].next,0,sizeof(aut[i].next));
      tree[i].clear();
    }
    sz=0,last=0,aut[0].link=-1;
  }
  int con(char c)//check for word size
  {
    return c-'a';
  }
  void insrt(int c)
  {
    int now=++sz;aut[now].len=aut[last].len+1;
    occur[now]=1;int p,q,cl;
    for(p=last;p!=-1&&!aut[p].next[c];p=aut[p].link)
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
        cl=++sz;aut[cl].len=aut[p].len+1;
        aut[cl].link=aut[q].link;
        memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));//for array
        //aut[cl].next=aut[q].next;//for map
        for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
          aut[p].next[c]=cl;
        aut[now].link=aut[q].link=cl;
      }
    }
    last=now;
  }
  void insrt(string s)
  {
    for(auto x:s)insrt(con(x));
  }
  void dfs(int now)
  {
    for(auto x:tree[now])
      dfs(x),occur[now]+=occur[x];
  }
  void makeTree(void)
  {
    for(int i=1;i<=sz;i++)
      tree[aut[i].link].push_back(i);
    dfs(0);
  }
  int num(string s)
  {
    int now=0;
    for(int i=0;i<s.size();i++)
      now=aut[now].next[con(s[i])];
    return now;
  }
}sam;
 int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;sam.clean();
  for(int i=1;i<=n;i++)
    sam.insrt(s),sam.last=0;
   return 0;
}