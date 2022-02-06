/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/03/2019 22:36                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 25000 KB                             
*  problem: https://codeforces.com/contest/802/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
 struct suffixAutomata
{
  struct node
  {
    int len,link,next[26];
  }aut[N+N+2];//2*insrt function call
  int sz,last,occur[N+N+2];
  vector<int>tree[N+N+2];
  void clean(int n=N)//must call before insert
  {
    for(int i=0;i<=n+n;i++)
    {
      memset(aut[i].next,0,sizeof(aut[i].next));
      tree[i].clear();
    }
    sz=0,last=0,aut[0].link=-1;
  }
  void insrt(int c)
  {
    int now=++sz;aut[now].len=aut[last].len+1;
    int p,q,cl;occur[now]=1;
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
        memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
        for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
          aut[p].next[c]=cl;
        aut[now].link=aut[q].link=cl;
      }
    }
    last=now;
  }
  void dfs(int now)
  {
    for(auto x:tree[now])
    {
      dfs(x);occur[now]+=occur[x];
    }
  }
  void makeTree(void)
  {
    for(int i=1;i<=sz;i++)
      tree[aut[i].link].push_back(i);
    dfs(0);
  }
  long cal(void)
  {
    long ans=0;
    for(int i=1;i<=sz;i++)
    {
      long sub=aut[i].len-aut[aut[i].link].len;
      ans+=sub*occur[i]*occur[i];
    }
    return ans;
  }
}sam;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    sam.clean(s.size());
    for(auto x:s)sam.insrt(x-'a');
    sam.makeTree();cout<<sam.cal()<<"\n";
  }
  return 0;
}