/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/27/2018 21:58                        
*  solution_verdict: Runtime error on test 1                 language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 40500 KB                             
*  problem: https://codeforces.com/contest/432/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int last,sz,occur[N+N],k;
vector<int>v[N+N];
string s;
struct automata
{
  int len,link,next[26],id;
}st[N+N+N];
void insrt(int c,int idx)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  st[now].id=idx;
  occur[now]=1;
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
      st[cl].id=idx;
       st[cl].link=st[q].link;
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
void process(void)
{
  for(int i=1;i<=sz;i++)
    v[st[i].len].push_back(i);
  for(int i=s.size();i>=1;i--)
    for(auto x:v[i])
      occur[st[x].link]+=occur[x];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  st[0].link=-1;
  for(int i=0;s[i];i++)insrt(s[i]-'a',i+1);
   process();
   //for(int i=1;i<=sz;i++)cout<<st[i].id<<endl;
   int now=sz;
  set<pair<int,int> >pr;
  while(true)
  {
    cout<<st[now].len<<" "<<st[now].id<<endl;
    if(st[now].len==st[now].id)
      pr.insert({st[now].id,occur[now]});
    now=st[now].link;
    if(now<=0)break;
  }
  while(pr.size())
  {
    pair<int,int>p=*pr.begin();
    cout<<p.first<<" "<<p.second<<endl;
    pr.erase(p);
  }
  return 0;
}