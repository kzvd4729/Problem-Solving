/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2021 22:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 93400 KB                             
*  problem: https://codeforces.com/gym/102700/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
const int inf=1e9;
 struct automata
{
  int len,link,next[26];
}aut[N+N+2];//2*insrt function call
int sz,last,occur[N+N+2];
void init(void)
{
  for(int i=0;i<=N+N;i++)
  {
    memset(aut[i].next,0,sizeof(aut[i].next));
    occur[i]=0;
  }
  sz=0,last=0,aut[0].link=-1;
}
void insrt(int c)
{
  int now=++sz;aut[now].len=aut[last].len+1;
  int p,q,cl;occur[now]=1;
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
string ans;
void ret(int now)
{
  for(int i=25;i>=0;i--)
  {
    if(aut[now].next[i])
    {
      ans.push_back((char)(i+'a'));
      return ret(aut[now].next[i]);
    }
  }
}
string merge(string a,string b)
{
  string s;s.push_back(a[0]);
  for(int i=1;i<(int)a.size();i++)
  {
    if(a[i]<b[0])return s+b;
    else if(a[i]>=b[0])s.push_back(a[i]);
  }
  return s+b;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;
   init();for(auto x:a)insrt(x-'a');
  ans.clear();ret(0);string c=ans;
   init();for(auto x:b)insrt(x-'a');
  ans.clear();ret(0);string d=ans;
   cout<<merge(c,d)<<endl;
   return 0;
}