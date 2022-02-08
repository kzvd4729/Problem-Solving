/****************************************************************************************
*  @author: kzvd4729                                         created: 10-08-2018 19:14:02                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.06 sec                                        memory_used: 21.8M                                
*  problem: https://www.codechef.com/AUG18A/problems/KCOMPRES
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long t,n,s,arr[N+2];
long seg[5*N+2];
pair<long,long>pp[N+2];
void upd(long node,long lo,long hi,long id,long vl)
{
  if(lo==hi)
  {
    seg[node]=vl;
    return ;
  }
  long md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
long query(long node,long lo,long hi,long lt,long rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  long md=(lo+hi)/2;
  long p1=query(node*2,lo,md,lt,rt);
  long p2=query(node*2+1,md+1,hi,lt,rt);
  return max(p1,p2);
}
bool ok(long xx)
{
  vector<pair<long,long> >tmp;
  memset(seg,0,sizeof(seg));
  long sum=0;pp[0]={-1,-1};
  for(long i=1;i<=n;i++)
  {
    if(pp[i].first!=pp[i-1].first)
    {
      sort(tmp.begin(),tmp.end());
      long cnt=0,here=0,pr=0,prid=0;
      for(long j=0;j<tmp.size();j++)
      {
        if(tmp[j].first-xx<=pr)
        {
          cnt++;
          here=max(here,tmp[j].second);
        }
        else
        {
          sum+=(cnt*1LL*here);
          cnt=1,here=tmp[j].second;
          for(long k=prid;k<j;k++)
            upd(1,1,n,tmp[k].first,here);
          prid=j;
        }
        pr=tmp[j].first;
      }
      sum+=(cnt*1LL*here);
      for(long k=prid;k<tmp.size();k++)
        upd(1,1,n,tmp[k].first,here);
      tmp.clear();
    }
    long id=pp[i].second;
    long mx=query(1,1,n,max(pp[i].second-xx,1LL),min(pp[i].second+xx,n));
    tmp.push_back({pp[i].second,mx+1});
  }
  sort(tmp.begin(),tmp.end());
  long cnt=0,here=0,pr=0,prid=0;
  for(long j=0;j<tmp.size();j++)
  {
    if(tmp[j].first-xx<=pr)
    {
      cnt++;
      here=max(here,tmp[j].second);
    }
    else
    {
      sum+=(cnt*1LL*here);
      cnt=1,here=tmp[j].second;
      for(long k=prid;k<j;k++)
        upd(1,1,n,tmp[k].first,here);
      prid=j;
    }
    pr=tmp[j].first;
  }
  sum+=(cnt*1LL*here);
  for(long k=prid;k<tmp.size();k++)
    upd(1,1,n,tmp[k].first,here);
  tmp.clear();
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
    for(long i=1;i<=n;i++)
    {
      cin>>arr[i];
      pp[i]={arr[i],i};
    }
    sort(pp+1,pp+n+1);
//
//    long i,j=n+1;
//    for(i=0;i<=n;i++)
//      if(!ok(i))
//      {
//        j=i;
//        break;
//      }
//    cout<<j<<endl;
    for(long i=n;i>=0;i--)
      if(ok(i))
      {
        cout<<i+1<<endl;
        break;
      }
//    long lo=0,hi=n,md;
//    while(hi-lo>3)
//    {
//      md=(lo+hi)/2;
//      if(ok(md))lo=md;
//      else hi=md;
//    }
//    long f=0;
//    for(md=hi;md>=lo;md--)
//    {
//      if(ok(md))
//      {
//        cout<<md+1<<endl;
//        f=1;
//        break;
//      }
//    }
  }
  return 0;
}