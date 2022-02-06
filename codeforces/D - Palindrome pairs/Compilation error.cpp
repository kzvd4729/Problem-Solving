/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2019 23:40                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/159/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int id[N+2],ix[N+2];
struct eertree
{
  int sz,last,palCnt[N+2];
  struct node
  {
    int next[26],len,link;
  }pal[N+2];
  void constructor(void)
  {
    memset(pal,0,sizeof(pal));
    memset(palCnt,0,sizeof(palCnt));
    pal[0].len=-1,pal[0].link=0;
    pal[1].len=0,pal[1].link=0;
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
      palCnt[sz]=palCnt[pal[last].link]+1;
      id[p]=palCnt[sz];
      /*number of palindrome ending index p*/
    }
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
   eertree er;er.constructor();
  er.build(s);
  for(int i=1;i<=s.size();i++)ix[i]=id[i];
  reverse(s.begin(),s.end());
  er.constructor();
  er.build(s);
   for(int i=2;i<=s.size();i++)
    id[i]+=id[i-1];
   long ans=0;
  for(int i=1;i<=s.size();i++)
    ans+=(1LL*ix[i]*id[s.size()-i]);
  cout<<ans<<endl;
  return 0;
}