/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-05 11:52:40                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-760
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e2+1;
int length,sz,last,f;
string s,mem,srt[N];
set<int>pos;
struct automata
{
  int len,link,id,clone,next[26];
}st[N+N];
void insrt(int c,int idx)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  st[now].id=idx;

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
      st[cl].id=st[q].id;
      st[cl].clone=1;
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
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>s)
  {
    mem=s;
    memset(st,0,sizeof(st));
    length=s.size();
    st[0].link=-1;
    sz=0;
    last=0;
    for(int i=0;i<length;i++)insrt(s[i]-'a',i+1);
    cin>>s;
    int mx=0,ll=0,now=0;
    pos.clear();
    for(int i=0;i<s.size();i++)
    {
      int c=s[i]-'a';
      if(st[now].next[c])
      {
        now=st[now].next[c];
        ll++;
      }
      else
      {
        int p;
        for(p=now;p!=-1&&!st[p].next[c];p=st[p].link);
        if(p==-1)
        {
          now=0;
          ll=0;
        }
        else
        {
          now=st[p].next[c];
          ll=st[p].len+1;
        }
      }
      if(ll==mx)
        pos.insert(st[now].id-mx+1);
      else if(ll>mx)
      {
        mx=ll;
        pos.clear();
        pos.insert(st[now].id-mx+1);
      }
    }
    if(f)cout<<endl;
    f=1;
    if(mx==0)
      cout<<"No common sequence."<<endl;
    else
    {
      int id=0;
      while(pos.size())
      {
        id++;
        int xx=*pos.begin();
        for(int i=xx;i<xx+mx;i++)
          srt[id].push_back(mem[i-1]);
        pos.erase(xx);
      }
      sort(srt+1,srt+id+1);
      for(int i=1;i<=id;i++)
      {
        cout<<srt[i]<<endl;
        srt[i].clear();
      }
    }
  }
  return 0;
}