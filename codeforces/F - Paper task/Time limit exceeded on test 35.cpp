/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/30/2018 21:53                        
*  solution_verdict: Time limit exceeded on test 35          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 465800 KB                            
*  problem: https://codeforces.com/contest/653/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int length,sz,last,occur[N+N+N];
int n,ans;
map<pair<int,int>,long>dp;
string s;
vector<int>v_len[N+N+N];
struct automata
{
  int len,link,id,clone,next[5];
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
long dfs(int now,int cnt)
{
  if(dp[{now,cnt}])return dp[{now,cnt}];
   long here=0;
   if(!cnt)here++;
   int c=0;
  if(st[now].next[c])
    here+=dfs(st[now].next[c],cnt+1);
  if(cnt)
  {
    c=')'-'(';
    if(st[now].next[c])
      here+=dfs(st[now].next[c],cnt-1);
  }
  return dp[{now,cnt}]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>s;
  length=s.size();
  st[0].link=-1;
  for(int i=0;i<length;i++)insrt(s[i]-'(',i+1);
   count_occurrence();
   occur[0]=0;
   cout<<dfs(0,0)-1<<endl;
    return 0;
}