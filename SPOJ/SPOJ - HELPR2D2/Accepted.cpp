/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-10 23:39:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 840                                        memory_used (MB): 18.4                            
*  problem: https://vjudge.net/problem/SPOJ-HELPR2D2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t,k,n,v,r;
char s[102];
struct segment
{
  int vl,idx;
}seg[4*N+2];
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node].vl=vl;
    seg[node].idx=id;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);

  if(seg[node*2].vl>seg[node*2+1].vl)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
segment query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {-1,-1};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  segment p1=query(node*2,lo,md,lt,rt);
  segment p2=query(node*2+1,md+1,hi,lt,rt);
  if(p1.vl>p2.vl)return p1;
  else return p2;
}
int convert(void)
{
  int sum=0;
  for(int i=0;i<strlen(s);i++)
    sum=sum*10+int(s[i]-'0');
  return sum;
}
void _search(int xx,int cnt)
{
  if(cnt==0)return ;
  int lo=1,hi=N,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    int tmp=query(1,1,N,1,md).vl;
    if(tmp>=xx)hi=md;
    else lo=md;
  }
  for(int i=lo;i<=hi;i++)
  {
    segment tmp=query(1,1,N,1,i);
    if(tmp.vl>=xx)
    {
      int wh=tmp.vl/xx;
      int zz=min(wh,cnt);
      upd(1,1,N,tmp.idx,tmp.vl-(zz*xx));
      cnt-=zz;
      _search(xx,cnt);
      break;
    }
  }
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    memset(seg,0,sizeof(seg));
    scanf("%d",&k);
    for(int i=1;i<=N;i++)upd(1,1,N,i,k);
    scanf("%d",&n);
    while(n)
    {
      scanf("%s",s);
      if(s[0]=='b')
      {
        scanf("%d",&r);
        scanf("%d",&v);
        _search(v,r);
        n-=r;
      }
      else
      {
        int xx=convert();
        _search(xx,1);
        n-=1;
      }
    }
    int ans=0,sum=0;
    for(int i=1;i<=N;i++)
    {
      int tmp=query(1,1,N,i,i).vl;
      if(tmp==k)break;
      ans++;
      sum+=tmp;
    }
    printf("%d %d\n",ans,sum);
  }
  return 0;
}