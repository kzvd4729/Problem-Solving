/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/29/2018 02:27                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 904 ms                                          memory_used: 178700 KB                            
*  problem: https://codeforces.com/contest/1043/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int sz,last,now[11],len[11];
int mat[11][N+2];
struct automata
{
  int len,link;
  unordered_map<int,int>next;
}st[11][N+N+2];
void insrt(int c,int id)
{
  int now=++sz;
  st[id][now].len=st[id][last].len+1;
   int p,q,cl;
  for(p=last;p!=-1&&!st[id][p].next[c];p=st[id][p].link)
    st[id][p].next[c]=now;
  if(p==-1)
    st[id][now].link=0;
  else
  {
    q=st[id][p].next[c];
    if(st[id][p].len+1==st[id][q].len)st[id][now].link=q;
    else
    {
      cl=++sz;
      st[id][cl].len=st[id][p].len+1;
      st[id][cl].link=st[id][q].link;
      st[id][cl].next=st[id][q].next;
      for( ;p!=-1&&st[id][p].next[c]==q;p=st[id][p].link)
        st[id][p].next[c]=cl;
      st[id][q].link=st[id][now].link=cl;
    }
  }
  last=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    st[i][0].link=-1;sz=0;last=0;
    for(int j=1;j<=n;j++)
    {
      cin>>mat[i][j];
      insrt(mat[i][j],i);
    }
  }
  if(m==1)
  {
    cout<<(n*1LL*(n*1LL+1))/2<<endl;
    exit(0);
  }
  long ans=0;
  for(int k=1;k<=n;k++)
  {
    int c=mat[m][k],here=1e8;
    for(int i=1;i<m;i++)
    {
      if(st[i][now[i]].next[c])
      {
        now[i]=st[i][now[i]].next[c];
        len[i]++;
      }
      else
      {
        int p;
        for(p=now[i];p!=-1&&!st[i][p].next[c];p=st[i][p].link);
        if(p==-1)
        {
          now[i]=0;len[i]=0;
        }
        else
        {
          now[i]=st[i][p].next[c];
          len[i]=st[i][p].len+1;
        }
      }
      here=min(here,len[i]);
    }
    ans+=(here*1LL);
  }
  cout<<ans<<endl;
  return 0;
}