/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/27/2019 12:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 44400 KB                             
*  problem: https://codeforces.com/gym/102428/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,inf=1e9;
struct automata
{
  int len,link,next[26];
}aut[N+N+2];
int sz,last;
void init(void)
{
  aut[0].link=-1;
}
void insrt(int c)
{
  int now=++sz;aut[now].len=aut[last].len+1;
  int p,q,cl;
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;init();
  for(auto x:s)insrt(x-'A');
   int q;cin>>q;
 while(q--)
 {
  cin>>s;int now=0,cnt=1;
  for(auto x:s)
  {
   int c=x-'A';
   if(aut[now].next[c])now=aut[now].next[c];
   else
   {
    cnt++;now=0;
    if(aut[now].next[c])now=aut[now].next[c];
    else {cnt=-1;break;}
   }
  }
  cout<<cnt<<"\n";
 }
   return 0;
}