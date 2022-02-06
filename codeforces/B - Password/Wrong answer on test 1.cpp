/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/27/2018 14:44                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 41500 KB                             
*  problem: https://codeforces.com/contest/126/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int last,sz,occur[N+N];
int k,dp[N+N];
vector<int>v[N+N];
string s;
struct automata
{
  int len,link,next[26],clone;
}st[N+N+N];
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  occur[now]=1;
  st[now].clone=0;
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
      st[cl].clone=1;
      st[cl].len=st[p].len+1;
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
  int l=s.size();
  st[0].link=-1;
  for(int i=0;i<l;i++)insrt(s[i]-'a');
   process();
   string print,ans;
  int now=0,f=0;
  for(int i=0;i<l;i++)
  {
    int c=s[i]-'a';
    print.push_back(s[i]);
    if(occur[now]>2)
    {
      ans=print;
      f=1;
    }
    now=st[now].next[c];
  }
  if(f)cout<<ans<<endl;
  else cout<<"Just a legend"<<endl;
  return 0;
}