/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-24 20:38:36                      
*  solution_verdict: Compilation error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-LCS2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,last,sz;
char s[12][N+2];
struct automata
{
  int len,link,next[26];
}st[12][N+N+2];
void insrt(int ii,int c,int id)
{
  int now=++sz;
  st[ii][now].len=st[ii][last].len+1;

  int p,q,cl;
  for(p=last;p!=-1&&!st[ii][p].next[c];p=st[ii][p].link)
    st[ii][p].next[c]=now;
  if(p==-1)
    st[ii][now].link=0;
  else
  {
    q=st[ii][p].next[c];
    if(st[ii][p].len+1==st[ii][q].len)
      st[ii][now].link=q;
    else
    {
      cl=++sz;
      st[ii][cl].len=st[ii][p].len+1;
      st[ii][cl].link=st[ii][q].link;
      memcpy(st[ii][cl].next,st[ii][q].next,sizeof(st[ii][cl].next));
      for( ;p!=-1&&st[ii][p].next[c]==q;p=st[ii][p].link)
        st[ii][p].next[c]=cl;
      st[ii][now].link=st[ii][q].link=cl;
    }
  }
  last=now;
}
int main()
{
  getchar();
  for(n=1; ;n++)
  {
    gets(s[n]);
    if(strlen(s[n])==0)break;
  }

  for(int i=1;i<n;i++)
  {
    sz=0,last=0;
    st[i][0].link=-1;
    for(int j=0;j<strlen(s[i]);j++)
      insrt(i,s[i][j]-'a',j);
  }
  int mx=0;
  for(int i=1;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      int now=0,match=0,p;
      for(int k=0;k<strlen(s[i]);k++)
      {
        int c=s[i][k]-'a';
        if(st[j][now].next[c])
        {
          match++;
          now=st[j][now].next[c];
        }
        else
        {
          for(p=now;p!=-1&&!st[j][p].next[c];p=st[j][p].link);
          if(p==-1)
          {
            now=0;
            match=0;
          }
          else
          {
            match=st[j][p].len+1;
            now=st[j][p].next[c];
          }
        }
      }
      mx=max(mx,match);
    }
  }
  printf("%d\n",mx);
  return 0;
}