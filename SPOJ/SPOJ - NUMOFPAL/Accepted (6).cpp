/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-24 20:33:59                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 4.3                             
*  problem: https://vjudge.net/problem/SPOJ-NUMOFPAL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
/*
every state of the tree is a palindromic substring.
there are atmost n distinct palindromic substring
of a string.
a transition marked c from X to Y means Y=cXc;
a suffix link from X to Y means Y is proper suffix of X.
*/
struct eertree
{
  int sz,last,occur[N+2],ans=0;
  vector<int>v[N+2];
  struct node
  {
    int next[26],len,link;
  }pal[N+2];
  void constructor(void)
  {
    memset(pal,0,sizeof(pal));
    memset(occur,0,sizeof(occur));
    for(int i=0;i<=N;i++)v[i].clear();
    pal[0].len=-1,pal[0].link=0;//odd root
    pal[1].len=0,pal[1].link=0;//even root
    sz=1,last=1;
    /*last keeps track of the largest palindromic
    substring suffix of till inserted string*/
  }
  void build(string s)
  {
    s="#"+s;
    for(int p=1;p<s.size();p++)
    {
      while(s[p-pal[last].len-1]!=s[p])last=pal[last].link;
      int x=pal[last].link,c=s[p]-'a';
      while(s[p-pal[x].len-1]!=s[p])x=pal[x].link;
      if(!pal[last].next[c])
      {
        pal[last].next[c]=++sz;
        pal[sz].len=pal[last].len+2;
        if(pal[sz].len==1)pal[sz].link=1;
        else pal[sz].link=pal[x].next[c];
      }
      last=pal[last].next[c];
    }
  }
  void dfs(int nd)
  {
    occur[nd]=1;
    for(auto x:v[nd])
    {
      dfs(x);
      occur[nd]+=occur[x];
    }
  }
  int occurence(void)
  {
    for(int i=1;i<=sz;i++)
      v[pal[i].link].push_back(i);
    dfs(0);
    for(int i=2;i<=sz;i++)
      ans+=occur[i];
    return ans;
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;eertree er;er.constructor();
  er.build(s);cout<<er.occurence()<<endl;
  return 0;
}