/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2018 22:45                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 654 ms                                          memory_used: 314400 KB                            
*  problem: https://codeforces.com/contest/235/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int q,length,sz,last,occur[N+N+2];
string s;
vector<int>v_len[N+N+2],tre[N+N+2];
struct automata
{
  int len,link,next[27];
}st[N+N];
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;
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
      st[cl].link=st[q].link;
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
       for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[q].link=st[now].link=cl;
    }
  }
  last=now;
}
void count_occurrence(void)
{
  for(int i=1;i<=sz;i++)
    v_len[st[i].len].push_back(i);
   for(int i=length;i>=1;i--)
  {
    for(int j=0;j<v_len[i].size();j++)
    {
      int tmp=v_len[i][j];
      occur[st[tmp].link]+=occur[tmp];
    }
  }
}
void make_suffixtree(void)
{
  for(int i=1;i<=sz;i++)
    tre[st[i].link].push_back(i);
}
int ret(string k)
{
  int now=0;
  for(auto x:k)
  {
    int c=x-'a';
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
  reverse(s.begin(),s.end());
  length=s.size();
  st[0].link=-1;
  for(int i=0;i<length;i++)insrt(s[i]-'a');
   count_occurrence();
  make_suffixtree();
 //  cout<<st[ret("ab")].link<<endl;
//
//  for(int i=0;i<=10;i++)
//    cout<<st[i].link<<endl;
   cin>>q;
  while(q--)
  {
    cin>>s;
    reverse(s.begin(),s.end());
    int l=s.size();
    s+=s;
    int now=0,ln=0,p,ans=0;
    map<int,int>mp;
    for(int i=0;i<s.size()-1;i++)
    {
      int c=s[i]-'a';
      if(st[now].next[c])
      {
        now=st[now].next[c];
        ln++;
      }
      else
      {
        for(p=now;p!=-1&&!st[p].next[c];p=st[p].link);
        if(p==-1)
        {
          now=0;
          ln=0;
        }
        else
        {
          now=st[p].next[c];
          ln=st[p].len+1;
        }
      }
      if(ln>=l)
      {
        while(true)
        {
          p=st[now].link;
          if(p==-1)break;
          if(st[p].len>=l)
          {
            now=p;
            ln=st[now].len;
          }
          else break;
        }
        if(mp[now]==0)
        {
          ans+=occur[now];
          mp[now]=1;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}