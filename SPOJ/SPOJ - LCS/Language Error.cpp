/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-22 11:10:47                      
*  solution_verdict: Language Error                          language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-LCS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2500;
struct node
{
  int len,link,next[26];
};
struct suffixAutomata
{
  int sz,last;node aut[N+N+2];//2*insrt function call
  suffixAutomata()
  {
    sz=0,last=0;aut[0].link=-1;
  }
  void insrt(int c)
  {
    int now=++sz;aut[now].len=aut[last].len+1;
    int p,q,cl;
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
  string a,b;cin>>a>>b;suffixAutomata sam;
  for(auto x:a)sam.insrt(x-'a');
  cout<<sam.longestCommonSubstring(b)<<endl;
  return 0;
}