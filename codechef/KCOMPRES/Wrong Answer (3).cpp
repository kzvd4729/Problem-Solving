/****************************************************************************************
*  @author: kzvd4729                                         created: 08-08-2018 16:14:40                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.52 sec                                        memory_used: 18M                                  
*  problem: https://www.codechef.com/AUG18A/problems/KCOMPRES
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t,n,s,arr[N+2];
int seg[5*N+2];
pair<int,int>pp[N+2];
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node]=vl;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  int p1=query(node*2,lo,md,lt,rt);
  int p2=query(node*2+1,md+1,hi,lt,rt);
  return max(p1,p2);
}
bool ok(int xx)
{
  vector<pair<int,int> >tmp;
  memset(seg,0,sizeof(seg));
  long sum=0;pp[0]={-1,-1};
  for(int i=1;i<=n;i++)
  {
    if(pp[i].first!=pp[i-1].first)
    {
      for(auto x:tmp)
        upd(1,1,n,x.first,x.second);
      tmp.clear();
    }
    int id=pp[i].second;
    int mx=query(1,1,n,max(pp[i].second-xx,1),min(pp[i].second+xx,n));
    sum+=((mx+1)*1LL);
    tmp.push_back({pp[i].second,mx+1});
  }
  return sum<=s;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];
      pp[i]={arr[i],i};
    }
    sort(pp+1,pp+n+1);
    int lo=0,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(ok(md))lo=md;
      else hi=md;
    }
    int f=0;
    for(md=hi;md>=lo;md--)
    {
      if(ok(md))
      {
        cout<<md+1<<endl;
        f=1;
        break;
      }
    }
    if(!f)cout<<1<<endl;
  }
  return 0;
}