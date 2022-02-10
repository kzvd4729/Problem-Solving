/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-22 18:58:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1616                                       memory_used (MB): 22.4                            
*  problem: https://vjudge.net/problem/LightOJ-1428
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e4;
int t,tc,sz,last,n,lt,rt;
int indx[N+N+2],vis[N+N+2],pos[N+N+2];
vector<int>tree[N+N+2];
char s[N+2],pt[N+2];
struct automata
{
  int len,link,idx;
  int next[27];
}st[N+N+2];
void insrt(int c,int id)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  st[now].idx=id;
  indx[id]=now;

  int p,q,cl;
  for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)
    st[p].next[c]=now;
  if(p==-1)
    st[now].link=0;
  else
  {
    q=st[p].next[c];
    if(st[p].len+1==st[q].len)
      st[now].link=q;
    else
    {
      cl=++sz;
      st[cl].len=st[p].len+1;
      st[cl].link=st[q].link;
      st[cl].idx=st[q].idx;
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
void suffix_tree(void)
{
  for(int i=1;i<=sz;i++)
    tree[st[i].link].push_back(i);
}
void position_of_occurences(int now)
{
  if(vis[now])return ;
  pos[st[now].idx-strlen(pt)+1]=st[now].idx-strlen(pt)+1;
  for(int i=0;i<tree[now].size();i++)
    position_of_occurences(tree[now][i]);
}
int first_position(void)
{
  int now=0;
  for(int i=1;i<=strlen(pt);i++)
  {
    int c=pt[i-1]-'a';
    if(st[now].next[c])now=st[now].next[c];
    else return -1;
  }
  return now;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    for(int i=1;i<=N+N;i++)
      tree[i].clear();
    memset(st,0,sizeof(st));
    scanf("%s",s);
    n=strlen(s);
    sz=0;last=0;
    st[0].link=-1;

    for(int i=1;i<=n;i++)
      insrt(s[i-1]-'a',i);
    suffix_tree();

    scanf("%s",pt);
    int tmp=first_position();

    memset(pos,0,sizeof(pos));
    if(tmp!=-1)
    {
      memset(vis,0,sizeof(vis));
      position_of_occurences(tmp);
      for(int i=n;i>=1;i--)
      {
        if(pos[i])continue;
        pos[i]=pos[i+1];
      }
    }

//    for(int i=1;i<=n;i++)
//      cout<<pos[i]<<" ";
//    cout<<endl;
    memset(st,0,sizeof(st));
    sz=0,last=0;
    st[0].link=-1;
    long ans=0;
    for(int i=n;i>=1;i--)
    {
      insrt(s[i-1]-'a',i);
      int len=st[indx[i]].len;
      int lcp=st[st[indx[i]].link].len;

      int lt,rt;
      lt=i+lcp;
      if(pos[i]==0)rt=n;
      else rt=pos[i]+strlen(pt)-2;
      if(lt>rt)continue;
      //cout<<lt<<" "<<rt<<endl;
      ans+=rt-lt+1;
    }
    printf("Case %d: %d\n",++tc,ans);
  }
  return 0;
}