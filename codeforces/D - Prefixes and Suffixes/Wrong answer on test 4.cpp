/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2018 14:09                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 45700 KB                             
*  problem: https://codeforces.com/contest/432/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int last,sz,occur[N+N];
int k,dp[N+N],lid[N+N];
vector<int>v[N+N],tr[N+N];
string s;
struct automata
{
  int len,link,next[26],clone,id;
}st[N+N+N];
void insrt(int c,int idx)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  occur[now]=1;
  st[now].clone=0;
  st[now].id=idx;
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
      st[cl].id=idx;
      st[cl].clone=1;
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
void make_tree(void)
{
  for(int i=1;i<=sz;i++)
    tr[st[i].link].push_back(i);
}
void random(void)
{
  for(int i=sz;i>=1;i--)
    lid[st[i].link]=max(lid[st[i].link],lid[i]);
}
int match(void)
{
  cin>>s;
  int now=0;
  for(int i=0;s[i];i++)
  {
    int c=s[i]-'A';
    if(st[now].next[c])
      now=st[now].next[c];
    else return -1;
  }
  return now;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  //s="fixprefixsuffix";
  int l=s.size();
  st[0].link=-1;
  for(int i=0;i<l;i++)insrt(s[i]-'A',i+1);
  process();
  make_tree();
  random();
   set<pair<int,int> >pr;
  int now=0;
  for(int i=0;s[i];i++)
  {
    int c=s[i]-'A';
    now=st[now].next[c];
    if(lid[now]==s.size())
      pr.insert({st[now].len,occur[now]});
  }
  cout<<pr.size()<<endl;
  while(pr.size())
  {
    pair<int,int>p=*pr.begin();
    cout<<p.first<<" "<<p.second<<endl;
    pr.erase(p);
  }
   //for(auto x:tr[match()])cout<<x<<endl;
    //cout<<match()<<endl;
   //cout<<st[sz].len<<endl;
 //  string print,ans;
//  int now=0,f=0;
//  for(int i=0;i<l;i++)
//  {
//    int c=s[i]-'A';
//    print.push_back(s[i]);
//    if(occur[now]>2)
//    {
//      ans=print;
//      f=1;
//    }
//    now=st[now].next[c];
//  }
//  if(f)cout<<ans<<endl;
//  else cout<<"Just a legend"<<endl;
  return 0;
}