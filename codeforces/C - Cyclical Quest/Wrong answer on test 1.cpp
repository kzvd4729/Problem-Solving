/****************************************************************************************
*  @author: kzvd4729                                         created: May/09/2018 18:23                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 269600 KB                            
*  problem: https://codeforces.com/contest/235/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6+1;
int len,sz,last,occur[N+N],n;
string s;
vector<int>length[N+N];
struct automata
{
  int len,link,id,clone,next[26];
}st[N+N];
map<int,int>mp;
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
void find_occurrences(void)
{
  for(int i=sz;i>=1;i--)
    length[st[i].len].push_back(i);
  for(int i=len;i>=1;i--)
    for(auto x:length[i])
      occur[st[x].link]+=occur[x];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  len=s.size();
  st[0].link=-1;
  for(int i=0;i<len;i++)insrt(s[i]-'a',i+1);
   find_occurrences();
   //cout<<st[0].next[0]<<endl;
   cin>>n;
  while(n--)
  {
    cin>>s;
    int l=s.size();
    s+=s;
    s.pop_back();
    int now=0,ans=0,f=0,i;
     for(i=0;i<l;i++)
    {
      int c=s[i]-'a';
      if(st[now].next[c])
        now=st[now].next[c];
      else
      {
        f=1;
        break;
      }
    }
    map<int,int>mp;
    int p,ln,d;
    if(i==l)
    {
      ans+=occur[now];
      mp[now]=1;
    }
    p=i;
    ln=i;
    //cout<<now<<" "<<ln<<endl;
    while(true)
    {
      now=st[now].link;
      if(now==-1)break;
      ln=st[now].len;
      if(p>=s.size())break;
      //cout<<now<<" "<<ln<<endl;
      while(true)
      {
        if(ln==l||p>=s.size())break;
        //cout<<now<<endl;
        if(st[now].next[s[p]-'a'])
        {
          now=st[now].next[s[p]-'a'];
          p++;
          ln++;
        }
        else break;
      }
      //cout<<ln<<" "<<now<<endl;
      if(ln==l&&mp[now]==0)
      {
        ans+=occur[now];
        mp[now]=1;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}