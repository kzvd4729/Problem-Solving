/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/25/2018 15:28                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 53400 KB                             
*  problem: https://codeforces.com/contest/427/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int sz,last,occur[2][N+N];
string s;
vector<int>v[2][N+N];
struct automata
{
  int len,link,next[26];
}st[2][N+N+2];
void insrt(int c,int k)
{
  int now=++sz;
  st[k][now].len=st[k][last].len+1;
  occur[k][now]=1;
   int p,q,cl;
  for(p=last;p!=-1&&!st[k][p].next[c];p=st[k][p].link)
    st[k][p].next[c]=now;
  if(p==-1)
    st[k][now].link=0;
  else
  {
    q=st[k][p].next[c];
    if(st[k][p].len+1==st[k][q].len)
      st[k][now].link=q;
    else
    {
      cl=++sz;
      st[k][cl].len=st[k][p].len+1;
      st[k][cl].link=st[k][q].link;
      memcpy(st[k][cl].next,st[k][q].next,sizeof(st[k][cl].next));
      for( ;p!=-1&&st[k][p].next[c]==q;p=st[k][p].link)
        st[k][p].next[c]=cl;
      st[k][now].link=st[k][q].link=cl;
    }
  }
  last=now;
}
void process(string xx,int k)
{
  for(int i=1;i<=sz;i++)
    v[k][st[k][i].len].push_back(i);
  for(int i=xx.size();i>=1;i--)
    for(auto x:v[k][i])
      occur[k][st[k][x].link]+=occur[k][x];
}
void build(void)
{
  cin>>s;
  sz=0;
  last=0;
  st[0][0].link=-1;
  for(int i=0;s[i];i++)insrt(s[i]-'a',0);
  process(s,0);
  cin>>s;
  sz=0;
  last=0;
  st[1][0].link=-1;
  for(int i=0;s[i];i++)insrt(s[i]-'a',1);
  process(s,1);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   build();
    return 0;
}