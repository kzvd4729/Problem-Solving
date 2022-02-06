/****************************************************************************************
*  @author: kzvd4729                                         created: May/20/2018 16:32                        
*  solution_verdict: Runtime error on test 1                 language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 22700 KB                             
*  problem: https://codeforces.com/contest/19/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int sz,last;
string s;
struct automata
{
  int len,link,next[26],idx;
}st[N+N+2];
void insrt(int c,int id)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  st[now].idx=id;
   int p,q,cl;
  for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)
    st[p].next[c]=now;
  if(p==-1)
    st[now].link=0;
  else
  {
    q=st[p].next[c];
    if(st[p].len+1==st[q].len)
      st[now].link=q;
    else
    {
      cl=++sz;
      st[cl].len=st[p].len+1;
      st[cl].link=st[q].link;
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  st[0].link=-1;
  for(int i=0;i<s.size();i++)
    insrt(s[i]-'a',i+1);
  cout<<sz<<endl;
  return 0;
}