/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/12/2018 20:28                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/452/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int sz[4],last,occur[4][N+N+2];
vector<int>len[4][N+2];
string s[5];
struct automata
{
  int len,link,next[26];
}st[4][N+N+2];
void insrt(int id,int c)
{
  int now=++sz[id],p,q,cl;
  st[id][now].len=st[id][last].len+1;
  for(p=last;p!=-1&&!st[id][p].next[c];p=st[id][p].link)
    st[id][p].next[c]=now;
  occur[id][now]=1;
   if(p==-1)st[id][now].link=0;
  else
  {
    q=st[id][p].next[c];
    if(st[id][p].len+1==st[id][q].len)
      st[id][now].link=q;
    else
    {
      cl=++sz[id];
      st[id][cl].len=st[id][p].len+1;st[id][cl].link=st[id][q].link;
      memcpy(st[id][cl].next,st[id][q].next,sizeof(st[id][q].next));
      for( ;p!=-1&&st[id][p].next[c]==q;p=st[id][p].link)
        st[id][p].next[c]=cl;
      st[id][now].link=st[id][q].link=cl;
    }
  }
  last=now;
}
void occurence(void)
{
  for(int j=1;j<=3;j++)
  {
    for(int i=1;i<=sz[j];i++)
    {
      len[j][st[j][i].len].push_back(i);
    }
  }
  for(int j=1;j<=3;j++)
  {
    for(int i=s[j].size();i>=1;i--)
    {
      for(auto x:len[j][i])
      {
        occur[j][st[j][x].link]+=occur[j][x];
      }
    }
  }
}
int tester(int id,string x)
{
  int now=0;
  for(auto xx:x)
  {
    int c=xx-'a';
    if(!st[id][now].next[c])return 0;
    now=st[id][now].next[c];
  }
  return occur[id][now];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s[1]>>s[2]>>s[3];dont complie;
//  if(s[1].size()>s[2].size())swap(s[1],s[2]);
//  if(s[1].size()>s[3].size())swap(s[1],s[3]);
   st[1][0].link=-1;st[2][0].link=-1;st[3][0].link=-1;
  for(auto x:s[1])insrt(1,x-'a');
  for(auto x:s[2])insrt(2,x-'a');
  for(auto x:s[3])insrt(3,x-'a');
  occurence();
   return 0;
}