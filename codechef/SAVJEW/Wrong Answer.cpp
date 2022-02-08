/****************************************************************************************
*  @author: kzvd4729                                         created: 22-09-2019 23:15:59                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 21.9M                                
*  problem: https://www.codechef.com/COOK110A/problems/SAVJEW
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int bit[N+2],mx[5*N+2],aa[N+2],n;
void add(int x,int vl)
{
  for( ;x<=n;x+=x&-x)
    bit[x]+=vl;
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret+=bit[x];
  return ret;
}
void build(int node,int lo,int hi)
{
  if(lo==hi){mx[node]=aa[lo];return ;}
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  mx[node]=max(mx[node*2],mx[node*2+1]);
}
void upd(int node,int lo,int hi,int id)//make mx=0
{
  if(lo==hi){mx[node]=0;return ;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id);
  else upd(node*2+1,md+1,hi,id);
  mx[node]=max(mx[node*2],mx[node*2+1]);
}
int get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>=lt&&hi<=rt)return mx[node];
  if(lo>rt||hi<lt)return 0;
  int md=(lo+hi)/2;
  int p1=get(node*2,lo,md,lt,rt);
  int p2=get(node*2+1,md+1,hi,lt,rt);
  return max(p1,p2);
}
int uu[N+2],vv[N+2];
map<int,int>po;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int q;cin>>n>>q;po.clear();
    for(int i=1;i<=n;i++)bit[i]=0;
    for(int i=1;i<=5*n;i++)mx[i]=0;
    long sum=0;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];po[aa[i]]=i;sum+=aa[i];
    }
    build(1,1,n);
    for(int i=1;i<=q;i++)
    {
      cin>>uu[i]>>vv[i];
      add(uu[i],1);add(vv[i]+1,-1);
    }
    int rm=0;
    for(int i=1;i<=q;i++)
    {
      int g=get(1,1,n,uu[i],vv[i]);
      sum-=g;
      if(g==0)continue;
      if(get(po[g])==1)rm=max(rm,g);
      upd(1,1,n,po[g]);
      add(uu[i],-1);add(vv[i]+1,1);
    }
    cout<<sum+rm*1LL<<endl;
  }
  return 0;
}