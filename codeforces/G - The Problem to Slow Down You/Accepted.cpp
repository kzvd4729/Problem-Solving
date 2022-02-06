/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2019 12:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 5740 ms                                         memory_used: 54800 KB                             
*  problem: https://codeforces.com/gym/100548/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
struct eertree
{
  int sz,last,palCnt[N+2];
  int suff[N+2];//number of palindrome ending at position i
  int occur[N+2];//number of occurrences for every state.
  struct node
  {
    int next[26],len,link;
  }pal[N+2];
  void constructor(void)
  {
    memset(pal,0,sizeof(pal));
    memset(palCnt,0,sizeof(palCnt));
    memset(occur,0,sizeof(occur));
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
         palCnt[sz]=1+palCnt[pal[sz].link];
        suff[p]=palCnt[sz];
      }
      else suff[p]=palCnt[pal[last].next[c]];
      last=pal[last].next[c];occur[last]++;
    }
  }
  void occurrences(void)
  {
    for(int i=sz;i>=2;i--)occur[pal[i].link]+=occur[i];
  }
}aa,bb;
long ans;
void dfs(int a,int b)
{
  for(int c=0;c<26;c++)
  {
    if(aa.pal[a].next[c]&&bb.pal[b].next[c])
    {
      ans+=1LL*aa.occur[aa.pal[a].next[c]]*bb.occur[bb.pal[b].next[c]];
      dfs(aa.pal[a].next[c],bb.pal[b].next[c]);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    string a;cin>>a;aa.constructor();
    aa.build(a);aa.occurrences();
     string b;cin>>b;bb.constructor();
    bb.build(b);bb.occurrences();
     ans=0;dfs(0,0);dfs(1,1);
    cout<<"Case #"<<++tc<<": ";
    cout<<ans<<"\n";
  }
  return 0;
}