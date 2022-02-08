/****************************************************************************************
*  @author: kzvd4729                                         created: 04-04-2020 20:05:11                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 2.95 sec                                        memory_used: 187.1M                               
*  problem: https://www.codechef.com/problems/MNMXAR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
struct segment
{
  int c[2],l[2],sm;
}seg[16+2][5*N+2];
void tooLazy(int id,int node,int lo,int hi)
{
  if(seg[id][node].l[0]!=-1)
  {
    seg[id][node].c[0]=(hi-lo+1)*seg[id][node].l[0];
    if(lo!=hi)
    {
      seg[id][node*2].l[0]=seg[id][node].l[0];
      seg[id][node*2+1].l[0]=seg[id][node].l[0];
    }
    seg[id][node].l[0]=-1;
  }
  if(seg[id][node].l[1]!=-1)
  {
    seg[id][node].c[1]=(hi-lo+1)*seg[id][node].l[1];
    if(lo!=hi)
    {
      seg[id][node*2].l[1]=seg[id][node].l[1];
      seg[id][node*2+1].l[1]=seg[id][node].l[1];
    }
    seg[id][node].l[1]=-1;
  }
  if(seg[id][node].c[0]==hi-lo+1)seg[id][node].sm=seg[id][node].c[1];
  else if(seg[id][node].c[1]==hi-lo+1)seg[id][node].sm=seg[id][node].c[0];
  else if(seg[id][node].c[0]==0||seg[id][node].c[1]==0)seg[id][node].sm=0;
}
void upd(int id,int node,int lo,int hi,int lt,int rt,int f,int vl)
{
  tooLazy(id,node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[id][node].l[f]=vl;tooLazy(id,node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(id,node*2,lo,md,lt,rt,f,vl);upd(id,node*2+1,md+1,hi,lt,rt,f,vl);
    seg[id][node].sm=seg[id][node*2].sm+seg[id][node*2+1].sm;
  seg[id][node].c[0]=seg[id][node*2].c[0]+seg[id][node*2+1].c[0];
  seg[id][node].c[1]=seg[id][node*2].c[1]+seg[id][node*2+1].c[1];
}
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    for(int i=0;i<18;i++)
    {
      for(int j=0;j<5*N+2;j++)
        seg[i][j].l[0]=-1,seg[i][j].l[1]=-1,seg[i][j].c[0]=0,seg[i][j].c[1]=0
            ,seg[i][j].sm=0;
    }
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    deque<pair<int,int> >inc,dec;long ans=0;
    inc.push_back({-1,0});dec.push_back({1e9,0});
    for(int i=1;i<=n;i++)
    {
      while(inc.back().first>=aa[i])inc.pop_back();
      //cout<<inc.back().second+1<<" "<<i<<" "<<aa[i]<<endl;
      for(int j=0;j<=16;j++)upd(j,1,1,n,inc.back().second+1,i,0,(bool)(aa[i]&(1
          <<j)));
      inc.push_back({aa[i],i});
      while(dec.back().first<=aa[i])dec.pop_back();
      //cout<<dec.back().second+1<<" "<<i<<" "<<aa[i]<<endl;
      for(int j=0;j<=16;j++)upd(j,1,1,n,dec.back().second+1,i,1,(bool)(aa[i]&(1
          <<j)));
      dec.push_back({aa[i],i});
      for(int j=0;j<=16;j++)ans+=(1LL*seg[j][1].sm*(1<<j));
    }
    cout<<ans<<"\n";
  }
  return 0;
}