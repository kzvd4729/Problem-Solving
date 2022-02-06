/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2018 19:11                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 202 ms                                          memory_used: 51900 KB                             
*  problem: https://codeforces.com/contest/633/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4+1;
int length,n,sz,last,occur[N+N],q,f;
string s,sss[10*N];
map<string,int>mp;
vector<int>v_len[N+N],tre[N+N],pos[N],yes;
struct automata
{
  int len,link,id,clone,next[26];
}st[N+N];
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
void find_path(int now,int id,int ssz)
{
  pos[st[now].id-ssz+1].push_back(id);
  for(auto x:tre[now])
    find_path(x,id,ssz);
}
void position_of_occurrence(string s,int id)
{
  int now=0;
  for(auto x:s)
  {
    int c=x-'a';
    if(!st[now].next[c])return ;
    now=st[now].next[c];
  }
  find_path(now,id,s.size());
}
void print_path(int now)
{
  if(now>n)
  {
    f=1;
    return ;
  }
  for(auto x:pos[now])
  {
    print_path(now+sss[x].size());
    if(f==1)
    {
      yes.push_back(x);
      return ;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
   cin>>s;
  length=s.size();
  st[0].link=-1;
  for(int i=0;i<length;i++)insrt(s[i]-'a',i+1);
   count_occurrence();
  make_suffixtree();
   cin>>q;
  for(int ii=1;ii<=q;ii++)
  {
    cin>>s;
    sss[ii]=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
    {
      if(s[i]>='A'&&s[i]<='Z')
        s[i]=s[i]-'A'+'a';
    }
    if(mp[s])continue;
    mp[s]=1;
    position_of_occurrence(s,ii);
  }
  print_path(1);
   for(int i=yes.size()-1;i>=0;i--)
    cout<<sss[yes[i]]<<" ";
  cout<<endl;
  return 0;
}