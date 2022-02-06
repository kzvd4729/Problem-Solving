/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/04/2019 21:46                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 33400 KB                             
*  problem: https://codeforces.com/contest/316/problem/G3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
 struct suffixAutomata
{
  struct node
  {
    int len,link,next[26];
  }aut[N+N+2];//2*insrt function call
  vector<int>tree[N+N+2];
  vector<int>vLen[N+2];
  map<int,int>cnt[N+N+2];
  vector<pair<int,int> >bad[N+N+2];
  int sz,last,occur[N+N+2];
  void clean(int n=N)//must call before insert
  {
    sz=0,last=0,aut[0].link=-1;
  }
  void insrt(int c)
  {
    int now=++sz;aut[now].len=aut[last].len+1;
    int p,q,cl;occur[now]=1;
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
        memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
        for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
          aut[p].next[c]=cl;
        aut[now].link=aut[q].link=cl;
      }
    }
    last=now;
  }
  void dfs(int now)
  {
    for(auto x:tree[now])
    {
      dfs(x);occur[now]+=occur[x];
    }
  }
  void makeTree(void)
  {
    for(int i=1;i<=sz;i++)
    {
      tree[aut[i].link].push_back(i);
      vLen[aut[i].len].push_back(i);
    }
    dfs(0);
  }
  void cal(string &s,int l,int r)
  {
    for(int i=0;i<=sz;i++)
      cnt[i].clear();
    int now=0,ln=0;
    for(auto &x:s)
    {
      int c=x-'a';
      if(aut[now].next[c])ln++;
      else
      {
        for( ;now!=-1&&!aut[now].next[c];now=aut[now].link);
        if(now==-1){now=0,ln=0;}
        ln=aut[now].len+1;
      }
      now=aut[now].next[c];
       cnt[now][ln]++;
    }
    for(int len=N;len>=1;len--)
    {
      for(auto stt:vLen[len])
      {
        for(auto x:cnt[stt])
        {
          int lnk=aut[stt].link;
          int ln=min(x.first,aut[lnk].len);
           cnt[lnk][ln]+=x.second;
        }
      }
    }
    for(int i=1;i<=sz;i++)
    {
      cnt[i][aut[i].len];
      int pr=0;
      for(auto x:cnt[i])
      {
        if(x.second<l||x.second>r)
          bad[i].push_back({pr+1,x.first});
        pr=x.first;
      }
    }
  }
  long ret(void)
  {
    long add=0;
    for(int i=1;i<=sz;i++)
    {
      int r=aut[i].len,l=aut[aut[i].link].len+1;
      int sz=r-l+1;
      int pr=0;
      sort(bad[i].begin(),bad[i].end());
      //cout<<i<<" ";
      for(auto x:bad[i])
      {
        //cout<<x.first<<" --> "<<x.second<<" ";
        int nwl=max(max(pr+1,l),x.first);
        int nwr=x.second;
         sz-=max(0,nwr-nwl+1);
        pr=x.second;
      }
      //cout<<endl;
      add+=sz;
    }
    return add;
  }
}sam;
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;sam.clean();
  for(auto x:s)sam.insrt(x-'a');
  sam.makeTree();
   int q;cin>>q;
  while(q--)
  {
    int l,r;cin>>s>>l>>r;sam.cal(s,l,r);
  }
  cout<<sam.ret()<<endl;
  return 0;
}