/****************************************************************************************
*  @author: kzvd4729                                         created: 10-08-2018 18:52:02                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.18 sec                                        memory_used: 17.9M                                
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
      sort(tmp.begin(),tmp.end());
      int cnt=0,here=0,pr=0,prid=0;
      for(int j=0;j<tmp.size();j++)
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
          for(int k=prid;k<j;k++)
            upd(1,1,n,tmp[k].first,here);
          prid=j;
        }
        pr=tmp[j].first;
      }
      sum+=(cnt*1LL*here);
      for(int k=prid;k<tmp.size();k++)
        upd(1,1,n,tmp[k].first,here);
      tmp.clear();
    }
    int id=pp[i].second;
    int mx=query(1,1,n,max(pp[i].second-xx,1),min(pp[i].second+xx,n));
    tmp.push_back({pp[i].second,mx+1});
  }
  sort(tmp.begin(),tmp.end());
  int cnt=0,here=0,pr=0,prid=0;
  for(int j=0;j<tmp.size();j++)
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
      for(int k=prid;k<j;k++)
        upd(1,1,n,tmp[k].first,here);
      prid=j;
    }
    pr=tmp[j].first;
  }
  sum+=(cnt*1LL*here);
  for(int k=prid;k<tmp.size();k++)
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
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];
      pp[i]={arr[i],i};
    }
    sort(pp+1,pp+n+1);
    int ans=0;
    for(int i=0;i<=n;i++)
      if(ok(i))ans++;
    cout<<ans<<endl;
  }
  return 0;
}