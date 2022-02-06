/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2018 18:46                        
*  solution_verdict: Runtime error on test 27                language: GNU C++17                               
*  run_time: 468 ms                                          memory_used: 189700 KB                            
*  problem: https://codeforces.com/contest/126/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=7e5;
int last,sz,occur[N+N];
int k,lid[N+N];
vector<int>v[N+2];
string s;
struct automata
{
  int len,link,next[26];
}st[N+N];
void insrt(int c,int idx)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  occur[now]=1;
  lid[now]=st[now].len;
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
      lid[cl]=st[cl].len;
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
void rndm(void)
{
  for(int i=s.size();i>=1;i--)
    for(auto x:v[i])
      lid[st[x].link]=max(lid[st[x].link],lid[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  int l=s.size();
  st[0].link=-1;
  for(int i=0;i<l;i++)insrt(s[i]-'a',i+1);
  process();
  rndm();
   string ans,print;
  int now=0;
  for(int i=0;s[i];i++)
  {
    int c=s[i]-'a';
    now=st[now].next[c];
    ans.push_back(s[i]);
    if(lid[now]==s.size()&&occur[now]>=3)
      print=ans;
  }
  if(print.size()==0)cout<<"Just a legend"<<endl;
  else cout<<print<<endl;
  return 0;
}