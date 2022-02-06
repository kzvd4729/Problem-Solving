/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2019 18:02                        
*  solution_verdict: Runtime error on test 12                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/616/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=6e2;
 struct suffixAutomata
{
  int sz,last;
  long occur[N+N+2];//numbers of path starting from state i
  struct node
  {
    int len,link,next[26];
  }aut[N+N+2];//2*insrt function call
  void clean(int n=N)//must call before insert
  {
    for(int i=0;i<=n+n;i++)
    {
      memset(aut[i].next,0,sizeof(aut[i].next));
    }
    sz=0,last=0,aut[0].link=-1;
  }
  int con(char c)//check for word size
  {
    return c-'a';
  }
  void insrt(int c,int ad)
  {
    int now=++sz;aut[now].len=aut[last].len+1;
    occur[now]=ad;int p,q,cl;
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
    //cout<<"---> "<<last<<endl;
  }
  void insrt(string s,int ad)
  {
    for(auto x:s)insrt(con(x),ad);
  }
  //number of occurrences for every state;
  long occurences(int n=N)//n=string size;
  {
    for(int i=sz;i>=1;i--)
      occur[aut[i].link]+=occur[i];
     long mx=0;
    /*vector<vector<int> >vLen(n+2);
    for(int i=1;i<=sz;i++)
      vLen[aut[i].len].push_back(i);
    for(int i=n;i>=1;i--)
      for(auto x:vLen[i])
        occur[aut[x].link]+=occur[x];*/
    for(int i=1;i<=sz;i++)
      mx=max(mx,1LL*aut[i].len*occur[i]);
    return mx;
  }
}sam;
int cc[N+2];string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;sam.clean();
  for(int i=1;i<=n;i++)
    cin>>s[i];
  for(int i=1;i<=n;i++)cin>>cc[i];
  for(int i=1;i<=n;i++)
  {
    //cout<<s[i]<<endl;
    sam.insrt(s[i],cc[i]);
    sam.last=0;
  }
  //for(int i=1;i<=sam.sz;i++)
    //cout<<sam.aut[i].link<<endl;
  cout<<sam.occurences()<<endl;
  return 0;
}