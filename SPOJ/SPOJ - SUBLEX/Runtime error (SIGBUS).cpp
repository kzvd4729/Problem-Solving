/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-01 21:43:55                      
*  solution_verdict: Runtime error (SIGBUS)                  language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-SUBLEX
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
struct suffixAutomata
{
  int sz,last,occur[N+N+2];
  long pathCnt[N+N+2];//numbers of path starting from state i
  struct node
  {
    int len,link,next[26];
  }aut[N+N+2];//2*insrt function call
  void clean(int n=N)//must call before insert
  {
    for(int i=0;i<=n+n;i++)
    {
      memset(aut[i].next,0,sizeof(aut[i].next));
      pathCnt[i]=0;
    }
    sz=0,last=0,aut[0].link=-1;
  }
  int con(char c)//check for word size
  {
    return c-'a';
  }
  void insrt(int c)
  {
    int now=++sz;aut[now].len=aut[last].len+1;
    occur[now]=1;int p,q,cl;
    for(p=last;p!=-1&&!aut[p].next[c];p=aut[p].link)
      aut[p].next[c]=now;
    if(p==-1)
      aut[now].link=0;
    else
    {
      q=aut[p].next[c];
      if(aut[p].len+1==aut[q].len)
        aut[now].link=q;
      else
      {
        cl=++sz;aut[cl].len=aut[p].len+1;
        aut[cl].link=aut[q].link;
        memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));//for array
        //aut[cl].next=aut[q].next;//for map
        for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
          aut[p].next[c]=cl;
        aut[now].link=aut[q].link=cl;
      }
    }
    last=now;
  }
  void insrt(string s)
  {
    for(auto x:s)insrt(con(x));
  }
  //number of occurrences for every state;
  void occurences(int n)//n=string size;
  {
    vector<vector<int> >vLen(n+2);
    for(int i=1;i<=sz;i++)
      vLen[aut[i].len].push_back(i);
    for(int i=n;i>=1;i--)
      for(auto x:vLen[i])
        occur[aut[x].link]+=occur[x];
  }
  long countPath(int now)
  {
    if(pathCnt[now])return pathCnt[now];
    pathCnt[now]=(bool)now;
    for(int i=0;i<26;i++)//word size
      if(aut[now].next[i])
        pathCnt[now]+=countPath(aut[now].next[i]);
    return pathCnt[now];
  }
  string kth(long k)
  {
    string ans;int now=0;
    if(k>pathCnt[0])return ans;
    while(k)
    {
      for(int i=0;i<26;i++)
      {
        if(!aut[now].next[i])continue;
        int nx=aut[now].next[i];
        if(pathCnt[nx]>=k)
        {
          ans.push_back((char)(i+'a'));
          k--;now=nx;break;
        }
        else k-=pathCnt[nx];
      }
    }
    return ans;
  }
  int longestCommonSubstring(string s)
  {
    int now=0,len=0,mx=0;
    for(auto x:s)
    {
      int c=con(x),p;
      if(aut[now].next[c])
        len++,now=aut[now].next[c];
      else
      {
        for(p=now;p!=-1&&!aut[p].next[c];p=aut[p].link);
        if(p==-1)now=0,len=0;
        else len=aut[p].len+1,now=aut[p].next[c];
      }
      if(len>mx)mx=len;
    }
    return mx;
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;suffixAutomata sam;sam.clean();
  sam.insrt(s);sam.countPath(0);
  int q;cin>>q;
  while(q--)
  {
    long x;cin>>x;
    cout<<sam.kth(x)<<"\n";
  }
  return 0;
}