/****************************************************************************************
*  @author: kzvd4729                                         created: 25-08-2019 17:37:25                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.10 sec                                        memory_used: 35.5M                                
*  problem: https://www.codechef.com/problems/PALPROB
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5+2;
long ans;
struct eertree
{
  int sz,last,palCnt[N+2],dp[N+2],sp[N+2][22];
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
  void cal(void)
  {
    memset(sp,-1,sizeof(sp));
    for(int i=2;i<=sz;i++)
      sp[i][0]=pal[i].link;
    for(int j=1;j<20;j++)
    {
      for(int i=2;i<=sz;i++)
      {
        if(sp[i][j-1]!=-1)
          sp[i][j]=sp[sp[i][j-1]][j-1];
      }
    }
    for(int i=2;i<=sz;i++)
    {
      dp[i]=1;int now=i;
      for(int j=20;j>=0;j--)
      {
        if(sp[now][j]==-1||pal[sp[now][j]].len<pal[i].len/2)continue;
        now=sp[now][j];
      }
      if(pal[now].len==pal[i].len/2)
        dp[i]+=dp[now];
      ans+=1LL*dp[i]*occur[i];
    }
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;eertree er;er.constructor();
    er.build(s);er.occurrences();
    ans=0;er.cal();cout<<ans<<endl;
  }
  return 0;
}