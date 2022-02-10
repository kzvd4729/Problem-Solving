/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-07 01:53:39                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 120                                        memory_used (MB): 258                             
*  problem: https://vjudge.net/problem/SPOJ-LCS2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int sz,last,now[11],len[11];
struct automata
{
  int len,link,next[26];
}st[11][N+N+2];
string s,ss[11];
void insrt(int c,int id)
{
  int now=++sz;
  st[id][now].len=st[id][last].len+1;

  int p,q,cl;
  for(p=last;p!=-1&&!st[id][p].next[c];p=st[id][p].link)
    st[id][p].next[c]=now;
  if(p==-1)
    st[id][now].link=0;
  else
  {
    q=st[id][p].next[c];
    if(st[id][p].len+1==st[id][q].len)st[id][now].link=q;
    else
    {
      cl=++sz;
      st[id][cl].len=st[id][p].len+1;
      st[id][cl].link=st[id][q].link;
      memcpy(st[id][cl].next,st[id][q].next,sizeof(st[id][cl].next));

      for( ;p!=-1&&st[id][p].next[c]==q;p=st[id][p].link)
        st[id][p].next[c]=cl;
      st[id][q].link=st[id][now].link=cl;
    }
  }
  last=now;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m=0;
  while(cin>>s)
  {
    if(s.size()==0)break;
    ss[++m]=s;
  }
  for(int cnt=1;cnt<m;cnt++)
  {
    s=ss[cnt];
    st[cnt][0].link=-1;
    sz=0;last=0;
    for(int i=0;s[i];i++)
      insrt(s[i]-'a',cnt);
  }
  s=ss[m];
  int ans=0;
  for(int k=0;s[k];k++)
  {
    int c=s[k]-'a',here=1e8;
    for(int i=1;i<m;i++)
    {
      if(st[i][now[i]].next[c])
      {
        now[i]=st[i][now[i]].next[c];
        len[i]++;
      }
      else
      {
        int p;
        for(p=now[i];p!=-1&&!st[i][p].next[c];p=st[i][p].link);
        if(p==-1)
        {
          now[i]=0;
          len[i]=0;
        }
        else
        {
          now[i]=st[i][p].next[c];
          len[i]=st[i][p].len+1;
        }
      }
      here=min(here,len[i]);
    }
    ans=max(ans,here);
  }
  cout<<ans<<"\n";
  return 0;
}