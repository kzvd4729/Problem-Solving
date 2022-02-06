/****************************************************************************************
*  @author: kzvd4729                                         created: May/17/2018 22:52                        
*  solution_verdict: Wrong answer on test 18                 language: GNU C++11                               
*  run_time: 60 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/278/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=10000;
int sz,last,n;
string s,tmp;
struct automata
{
  int len,link,next[28];
}st[N+N];
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
  while(n--)
  {
    cin>>tmp;
    tmp+="{";
    s+=tmp;
  }
  st[0].link=-1;
  for(int i=0;i<s.size();i++)
    insrt(s[i]-'a');
  string ans;
  int now=0;
  while(true)
  {
    for(int c=0;c<26;c++)
    {
      if(!st[now].next[c])
      {
        ans.push_back(char(c+'a'));
        cout<<ans<<endl;
        return 0;
      }
    }
    ans.push_back('a');
    now=st[now].next[0];
  }
  return 0;
}