/****************************************************************************************
*  @author: kzvd4729                                         created: May/03/2018 19:53                        
*  solution_verdict: Compilation error                       language: GNU C++11                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/653/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5+1;
const int a=40;
int sz,last;
struct automata
{
  int link,len,id,clone,next[26];
}st[N+N];
void insrt(int c,int idx)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  st[now].id=idx;
  st[now].clone=0;
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
      st[cl].id=st[q].id;
      st[cl].len=st[p].len+1;
      st[cl].link=st[q].link;
      st[cl].next=st[q].next;
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
   cin>>n;
  cin>>s;
  st[0].link=-1;
  for(int i=0;i<n;i++)
    insrt(s[i]-a,i+1);
   return 0;
}