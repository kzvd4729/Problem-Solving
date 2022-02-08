/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2018 21:59:47                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.19 sec                                        memory_used: 55.8M                                
*  problem: https://www.codechef.com/APRIL18A/problems/CUTPLANT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=1e5;
int seg[4*N],x,lazy[4*N],arr[N+2],t,n,print,brr[4*N],_seg[4*N];
int sp[N+2][22],sp1[N+2][22],sp3[N+2][22],sp4[N+2][22];
vector<pair<int,int> >vc;
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]=arr[lo];
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lazy[node])
  {
    seg[node]=lazy[node];
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node]=vl;
    if(lo!=hi)
    {
      lazy[node*2]=vl;
      lazy[node*2+1]=vl;
    }
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lazy[node])
  {
    seg[node]=lazy[node];
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo>rt||hi<lt)return inf;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return min(query(node*2,lo,md,lt,rt),query(node*2+1,md+1,hi,lt,rt));
}
void sparse_table(void)
{
  for(int i=1;i<=n;i++)sp[i][0]=arr[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      int x=i+(1<<(j-1));
      sp[i][j]=sp[i][j-1];
      if(x>n)continue;
      sp[i][j]=min(sp[i][j],sp[x][j-1]);
    }
  }
  for(int i=1;i<=n;i++)sp1[i][0]=arr[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      int x=i-(1<<(j-1));
      sp1[i][j]=sp1[i][j-1];
      if(x<=0)continue;
      sp1[i][j]=min(sp1[i][j],sp1[x][j-1]);
    }
  }
  for(int i=1;i<=n;i++)sp3[i][0]=brr[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      int x=i+(1<<(j-1));
      sp3[i][j]=sp3[i][j-1];
      if(x>n)continue;
      sp3[i][j]=max(sp3[i][j],sp3[x][j-1]);
    }
  }
  for(int i=1;i<=n;i++)sp4[i][0]=brr[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      int x=i-(1<<(j-1));
      sp4[i][j]=sp4[i][j-1];
      if(x<=0)continue;
      sp4[i][j]=max(sp4[i][j],sp4[x][j-1]);
    }
  }
}
int sp_query1(int lt,int rt)
{
  if(lt==rt)return arr[lt];
  int x=rt-lt+1;
  int z=31-__builtin_clz(x);
  return min(sp[lt][z],sp1[rt][z]);
}
int sp_query2(int lt,int rt)
{
  if(lt==rt)return brr[lt];
  int x=rt-lt+1;
  int z=31-__builtin_clz(x);
  return max(sp3[lt][z],sp4[rt][z]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    memset(seg,0,sizeof(seg));
    memset(_seg,0,sizeof(_seg));
    memset(lazy,0,sizeof(lazy));
    vc.clear();
    print=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
      cin>>brr[i];
      vc.push_back({brr[i],i});
    }
    build(1,1,n);
    sparse_table();
    int f=0;
    for(int i=1;i<=n;i++)if(brr[i]>arr[i])f=1;
    if(f==1)
    {
      cout<<-1<<endl;
      continue;
    }
    sort(vc.begin(),vc.end());
    reverse(vc.begin(),vc.end());
    for(auto x:vc)
    {
      int id=x.second;
      int vl=x.first;
      int lo,hi,md,lt,rt;
      if(query(1,1,n,id,id)==vl)continue;
      print++;
      lo=id;
      hi=n;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(sp_query1(id,md)<vl||sp_query2(id,md)>vl)hi=md;
        else lo=md;
      }
      for(int i=hi;i>=lo;i--)
      {
        if(sp_query1(id,i)>=vl&&sp_query2(id,i)<=vl)
        {
          rt=i;
          break;
        }
      }
      lo=1;
      hi=id;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(sp_query1(md,id)<vl||sp_query2(md,id)>vl)lo=md;
        else hi=md;
      }
      for(int i=lo;i<=hi;i++)
      {
        if(sp_query1(i,id)>=vl&&sp_query2(i,id)<=vl)
        {
          lt=i;
          break;
        }
      }
      upd(1,1,n,lt,rt,vl);
    }
    cout<<print<<endl;
  }
  return 0;
}