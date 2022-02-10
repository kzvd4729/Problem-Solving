/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-22 17:05:51                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 220                                        memory_used (MB): 54.3                            
*  problem: https://vjudge.net/problem/SPOJ-NSUBSTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=250000;
struct node
{
  int len,link,next[26];
};
struct suffixAutomata
{
  int sz,last,occur[N+N+2];node aut[N+N+2];//2*insrt function call
  suffixAutomata()
  {
    sz=0,last=0;aut[0].link=-1;
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
        memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
        for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
          aut[p].next[c]=cl;
        aut[now].link=aut[q].link=cl;
      }
    }
    last=now;
  }
  vector<int>vLen[N+2];
  void occurences(void)
  {
    for(int i=1;i<=sz;i++)
      vLen[aut[i].len].push_back(i);
    for(int i=N;i>=1;i--)//N=string size;
      for(auto x:vLen[i])
        occur[aut[x].link]+=occur[x];
  }
  int longestCommonSubstring(string s)
  {
    int now=0,len=0,mx=0;
    for(auto x:s)
    {
      int c=x-'a',p;
      if(aut[now].next[c])
        len++,now=aut[now].next[c];
      else
      {
        for(p=now;p!=-1&&!aut[p].next[c];p=aut[p].link);
        if(p==-1)now=0,len=0;
        else len=aut[p].len+1,now=aut[p].next[c];
      }
      if(len>mx)mx=len;
    }
    return mx;
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;suffixAutomata sam;
  for(auto x:s)sam.insrt(x-'a');
  sam.occurences();
  vector<int>ans(s.size()+1,0);
  for(int i=1;i<=sam.sz;i++)
  {
    int len=sam.aut[i].len;
    ans[len]=max(ans[len],sam.occur[i]);
  }
  for(int i=1;i<=s.size();i++)
    cout<<ans[i]<<"\n";
  return 0;
}