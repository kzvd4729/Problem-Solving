/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2019 20:35                        
*  solution_verdict: Runtime error on test 3                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1073/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int ent[N+2],tim,index[N+2];
struct suffixAutomata
{
  int sz,last,occur[N+N+2];
  struct node
  {
    int len,link,next[26];
  }aut[N+N+2];//2*insrt function call
  vector<int>tree[N+2];
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
  void insrt(int c,int id)
  {
    int now=++sz;aut[now].len=aut[last].len+1;
    occur[now]=1;int p,q,cl;index[id]=now;
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
  void dfs(int nd)
  {
    ent[nd]=++tim;
    for(auto x:tree[nd])
      dfs(x);
  }
  void makeTree(void)
  {
    for(int i=1;i<=sz;i++)
      tree[aut[i].link].push_back(i);
  }
}sam;
pair<int,int>pp[N+2];
bool cmp(pair<int,int>a,pair<int,int>b)
{
  int x=a.first,y=b.first;
  return ent[index[x]]<ent[index[y]];
}
string s;
int match(int i,int j)
{
  for(int k=-1; ;k++)
    if(i+k==s.size()||j+k==s.size()||s[i+k]!=s[j+k])
      return k+1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  sam.clean();cin>>s;
  for(int i=s.size()-1;i>=0;i--)
    sam.insrt(s[i]-'a',i+1);
  sam.makeTree();sam.dfs(0);
  while(q--)
  {
    int a,b;cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
      cin>>pp[i].first;pp[i].second=1;
    }
    for(int i=a+1;i<=a+b;i++)
    {
      cin>>pp[i].first;pp[i].second=2;
    }
    sort(pp+1,pp+a+b+1,cmp);
    /*
    cout<<endl<<endl;
    for(int i=1;i<=a+b;i++)
      cout<<pp[i].first<<" "<<pp[i].second<<endl;
    */
    int pra=-1,prb=-1,asam=0,bsam=0;
    long ans=0;
    vector<int>aa,bb;
    for(int i=1;i<=a+b;i++)
    {
      if(pp[i].second==1)
      {
        if(prb!=-1)
        {
          int mt=match(prb,pp[i].first);
          ans+=mt;
          for(auto x:bb)
          {
            mt=min(mt,x);ans+=mt;
            if(mt==0)break;
          }
        }
        if(pra!=-1)aa.push_back(match(pra,pp[i].first));
        pra=pp[i].first;
      }
      else
      {
        if(pra!=-1)
        {
          int mt=match(pra,pp[i].first);
          ans+=mt;
          for(auto x:aa)
          {
            mt=min(mt,x);ans+=mt;
            if(mt==0)break;
          }
        }
        if(prb!=-1)bb.push_back(match(prb,pp[i].first));
        prb=pp[i].first;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}