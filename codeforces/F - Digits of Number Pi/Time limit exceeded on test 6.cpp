/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/02/2018 14:44                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/585/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=1e3;
int sz,last,tr;
string s,a,b;
struct automata
{
  int len,link,next[12];
}st[N+N+2];
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
long dfs(int ii,int now,int f1,int f2,int mt)
{
  if(ii>=a.size())
  {
    if(mt>=tr)return 1LL;
    else return 0LL;
  }
  int lo=a[ii]-'0';
  int hi=b[ii]-'0';
   if(f1)lo=0;
  if(f2)hi=9;
   long here=0;int tnow,tmt,p;
  for(int c=lo;c<=hi;c++)
  {
    if(mt>=tr)
    {
      here=(here+dfs(ii+1,now,f1|(c>(a[ii]-'0')),f2|(c<(b[ii]-'0')),mt))%mod;
    }
    else
    {
      if(st[now].next[c])
      {
        tnow=st[now].next[c];
        tmt=mt+1;
      }
      else
      {
        for(p=now;p!=-1&&!st[p].next[c];p=st[p].link);
        if(p==-1)
        {
          tnow=0;
          tmt=0;
        }
        else
        {
          tmt=st[p].len+1;
          tnow=st[p].next[c];
        }
      }
      here=(here+dfs(ii+1,tnow,f1|(c>(a[ii]-'0')),f2|(c<(b[ii]-'0')),tmt))%mod;
    }
  }
  return here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin>>s>>a>>b;
  tr=a.size()/2;
  st[0].link=-1;
  for(auto x:s)insrt(x-'0');
   cout<<dfs(0,0,0,0,0)<<endl;
   return 0;
}