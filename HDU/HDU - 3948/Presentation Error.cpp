/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-11-26 15:13:54                      
*  solution_verdict: Presentation Error                      language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-3948
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;

//..............................................................................
/*
there can be atmost n distinct palindromic substring of a string of length n.
every node of an eertree is a palindromic substring(and two roots for odd even)
a transition marked c from X to Y means Y=cXc;
a suffix link from X to Y means Y is proper suffix of X.
*/
int sz,last;
struct node
{
  int next[26],len,link;  
}pal[N+2];
void init()
{
  pal[0].link=0;pal[0].len=-1;//odd length root
  pal[1].link=0;pal[1].len=0;//even length root
  sz=1,last=1;
  //last keeps track of the lps suffix of till inserted string
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
      pal[last].next[c]=++sz;pal[sz].len=pal[last].len+2;
      if(pal[sz].len==1)pal[sz].link=1;
      else pal[sz].link=pal[x].next[c];
    }
    last=pal[last].next[c];
  }
}
void clear(int n)
{
  for(int i=0;i<=n;i++)
    memset(pal[i].next,0,sizeof(pal[i].next));
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    string s;cin>>s;init();
    build(s);cout<<"Case #"<<++tc<<":"<<sz-1<<"\n";
    clear(s.size());
  }

  return 0;
}