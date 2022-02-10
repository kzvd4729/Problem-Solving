/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-08 20:45:39                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 170                                        memory_used (MB): 48.1                            
*  problem: https://vjudge.net/problem/SPOJ-SUBLEX
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=90000;
int sz,last,occur[N+N+2],lid[N+N+2],dp[N+N+2];
vector<int>v_len[N+2],tre[N+N+2],pos;
string ans;
struct automata
{
 int len,link,next[26],id;
}st[N+N+2];
void insrt(int c,int idx)
{
  int now=++sz;st[now].len=st[last].len+1;
  occur[now]=1;st[now].id=idx;
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
      cl=++sz;st[cl].id=idx;
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
void count_occurences(int z)
{
 for(int i=1;i<=sz;i++)
    v_len[st[i].len].push_back(i);
  for(int i=z;i>=1;i--)
    for(auto x:v_len[i])
      occur[st[x].link]+=occur[x];
}
void make_tree(void)
{
  for(int i=1;i<=sz;i++)
    tre[st[i].link].push_back(i);
}
int match(string s)
{
  int now=0;
  for(int i=0;s[i];i++)
  {
    int c=s[i]-'a';
    if(st[now].next[c])
      now=st[now].next[c];
    else return -1;
  }
  return now;
}
void find_path(int now,int ssz)
{
  pos.push_back(st[now].id-ssz+1);
  for(auto x:tre[now])
    find_path(x,ssz);
}
void position_of_occurrence(string s)
{
  int now=0;
  for(auto x:s)
  {
    int c=x-'a';
    if(!st[now].next[c])return ;
    now=st[now].next[c];
  }
  find_path(now,s.size());
}
void _clear(int z)
{

 for(int i=0;i<=z;i++)
 {
  occur[i]=0;v_len[i].clear();
 }
 for(int i=0;i<=z+z;i++)
 {
  st[i].len=0;st[i].link=0;
  st[i].id=0;dp[i]=-1;
  memset(st[i].next,0,sizeof(st[i].next));
  tre[i].clear();
 }
 pos.clear();
 sz=0;last=0;st[0].link=-1;
}
int dfs(int now)
{
  if(dp[now]!=-1)return dp[now];
  dp[now]=1;
  for(int i=0;i<26;i++)
    if(st[now].next[i])dp[now]+=dfs(st[now].next[i]);
  return dp[now];
}
void klex(int now,int k)
{
  for(int i=0;i<26;i++)
  {
    if(!st[now].next[i]||!k)continue;
    int tmp=dp[st[now].next[i]];
    if(tmp>=k)
    {
      ans.push_back((char)(i+'a'));
      k--;
      klex(st[now].next[i],k);
      break;
    }
    else k-=tmp;
  }
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);

 string s;cin>>s;
  _clear(s.size());
  for(int i=0;s[i];i++)
    insrt(s[i]-'a',i+1);
  dfs(0);
  int q;cin>>q;
  while(q--)
  {
    int k;cin>>k;
    ans.clear();
    klex(0,k);
    cout<<ans<<endl;
  }
 return 0;
}