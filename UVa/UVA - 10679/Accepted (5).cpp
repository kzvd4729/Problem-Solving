/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-01 17:53:05                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 130                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10679
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=1e5;
int t,tc,last,sz,q;
struct automata
{
  int len,link;
  map<char,int>next;
}st[N+N+2];
string s;
void insrt(char c)
{
  int now=++sz;
  st[now].len=st[last].len+1;

  int p,q;
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
      int cl=++sz;
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
bool match(string s)
{
  int now=0;
  for(auto c:s)
  {
    if(!st[now].next[c])return false;
    now=st[now].next[c];
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>s;
    for(int i=0,ssz=s.size();i<=2*ssz;i++)
    {
      st[i].len=0;
      st[i].link=0;
      st[i].next.clear();
    }
    last=0,sz=0;
    st[0].link=-1;
    for(auto x:s)
      insrt(x);
    cin>>q;
    while(q--)
    {
      cin>>s;
      if(match(s))cout<<'y'<<endl;
      else cout<<'n'<<endl;
    }
  }
  return 0;
}