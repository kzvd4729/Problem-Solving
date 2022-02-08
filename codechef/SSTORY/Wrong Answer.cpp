/****************************************************************************************
*  @author: kzvd4729                                         created: 01-11-2018 10:12:55                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 68.4M                                
*  problem: https://www.codechef.com/problems/SSTORY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=250000;
int length,sz,last;
struct automata
{
  int len,link;
  int next[26];
}st[N+N+2];
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;
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
      st[q].link=st[now].link=cl;
    }
  }
  last=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;st[0].link=-1;
  for(auto x:s)insrt(x-'a');
  cin>>s;
  int now=0,ln=0,mx=0,id;
  for(int i=0;s[i];i++)
  {
    int c=s[i]-'a';
    if(st[now].next[c])now=st[now].next[c],ln++;
    else
    {
      for(;now!=-1&&!st[now].next[c];now=st[now].link);
      if(now==-1)now=0,ln=0;
      else
      {
        ln=st[now].len+1;
        now=st[now].next[c];
      }
    }
    if(ln>mx)mx=ln,id=i;
  }
  if(!ln)cout<<ln<<endl;
  else
  {
    cout<<s.substr(id-ln+1,ln)<<endl;
    cout<<ln<<endl;
  }
  return 0;
}