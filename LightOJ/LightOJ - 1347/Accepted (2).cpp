/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-05 14:54:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 72                                         memory_used (MB): 6.5                             
*  problem: https://vjudge.net/problem/LightOJ-1347
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3+1;
int sz,last,tc,t;
string s;
struct automata
{
  int len,link,id,clone,next[26];
}st[4][N+N];
void insrt(int ii,int c,int idx)
{
  int now=++sz;
  st[ii][now].len=st[ii][last].len+1;
  st[ii][now].id=idx;

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
      st[ii][cl].id=st[ii][q].id;
      st[ii][cl].clone=1;
      memcpy(st[ii][cl].next,st[ii][q].next,sizeof(st[ii][cl].next));

      for( ;p!=-1&&st[ii][p].next[c]==q;p=st[ii][p].link)
        st[ii][p].next[c]=cl;
      st[ii][q].link=st[ii][now].link=cl;
    }
  }
  last=now;
}
void make_automata(int ii,string s)
{
  sz=0,last=0;
  memset(st[ii],0,sizeof(st[ii]));
  st[ii][0].link=-1;
  for(int i=0;i<s.size();i++)
    insrt(ii,s[i]-'a',i+1);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>s;
    make_automata(1,s);
    cin>>s;
    make_automata(2,s);

    cin>>s;

    int now1=0,now2=0,ll=0,mx=0;
    for(int i=0;i<s.size();i++)
    {
      int c=s[i]-'a';
      if(st[1][now1].next[c]&&st[2][now2].next[c])
      {
        now1=st[1][now1].next[c];
        now2=st[2][now2].next[c];
        ll++;
      }
      else
      {
        int p1,p2;
        for(p1=now1;p1!=-1&&!st[1][p1].next[c];p1=st[1][p1].link);
        for(p2=now2;p2!=-1&&!st[2][p2].next[c];p2=st[2][p2].link);
        if(p1==-1)
        {
          now1=0;
          ll=0;
        }
        else now1=st[1][p1].next[c];
        if(p2==-1)
        {
          now2=0;
          ll=0;
        }
        else now2=st[2][p2].next[c];
        if(p1!=-1&&p2!=-1)
          ll=min(st[1][p1].len,st[2][p2].len)+1;
      }
      mx=max(mx,ll);
    }
    cout<<"Case "<<++tc<<": "<<mx<<endl;
  }
  return 0;
}