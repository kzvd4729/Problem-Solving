/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-25 19:09:29                      
*  solution_verdict: Runtime error (SIGSEGV)                 language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-LPS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5+2;
struct eertree
{
  int sz,last;
  struct node
  {
    int next[26],len,link;
  }pal[N+2];
  void constructor(void)
  {
    //memset(pal,0,sizeof(pal));
    pal[0].len=-1,pal[0].link=0;//odd root
    pal[1].len=0,pal[1].link=0;//even root
    sz=1,last=1;
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
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  eertree er;er.constructor();er.build(s);
  int mx=0;
  for(int i=2;i<=er.sz;i++)
    mx=max(mx,er.pal[i].len);
  cout<<mx<<endl;
  return 0;
}