/****************************************************************************************
*  @author: kzvd4729                                         created: May/18/2018 13:48                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 62 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/278/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=10000;
int sz,last,n;
string s,tmp;
struct automata
{
  int len,link,next[28];
}st[N+N];
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;
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
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
bool checker(string x)
{
  int now=0;
  for(int i=0;i<x.size();i++)
  {
    int c=x[i]-'a';
    if(st[now].next[c])
      now=st[now].next[c];
    else return true;
  }
  return false;
}
void len1(void)
{
  string tmp;
  for(int i=0;i<26;i++)
  {
    tmp.clear();
    tmp.push_back(char(i+'a'));
    if(checker(tmp))
    {
      cout<<tmp<<endl;
      exit(0);
    }
  }
}
void len2(void)
{
  string tmp;
  for(int i=0;i<26;i++)
  {
    for(int j=0;j<26;j++)
    {
      tmp.clear();
      tmp.push_back(char(i+'a'));
      tmp.push_back(char(j+'a'));
      if(checker(tmp))
      {
        cout<<tmp<<endl;
        exit(0);
      }
    }
  }
}
void len3(void)
{
  string tmp;
  for(int i=0;i<26;i++)
  {
    for(int j=0;j<26;j++)
    {
      for(int k=0;k<26;k++)
      {
        tmp.clear();
        tmp.push_back(char(i+'a'));
        tmp.push_back(char(j+'a'));
        tmp.push_back(char(k+'a'));
        if(checker(tmp))
        {
          cout<<tmp<<endl;
          exit(0);
        }
      }
    }
  }
}
void len4(void)
{
  string tmp;
  for(int i=0;i<26;i++)
  {
    for(int j=0;j<26;j++)
    {
      for(int k=0;k<26;k++)
      {
        for(int kk=0;kk<26;kk++)
        {
          tmp.clear();
          tmp.push_back(char(i+'a'));
          tmp.push_back(char(j+'a'));
          tmp.push_back(char(k+'a'));
          tmp.push_back(char(kk+'a'));
          if(checker(tmp))
          {
            cout<<tmp<<endl;
            exit(0);
          }
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  while(n--)
  {
    cin>>tmp;
    tmp+="{";
    s+=tmp;
  }
  st[0].link=-1;
  for(int i=0;i<s.size();i++)
    insrt(s[i]-'a');
   len1();
  len2();
  len3();
  len4();
   return 0;
}