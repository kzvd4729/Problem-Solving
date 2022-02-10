/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-25 14:22:27                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1120
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=6e4,inf=1e9;

//..............................................................................
int aa[N+2],bb[N+2],cc[N+2],dd[N+2];
struct segment
{
  int l,r,cnt,sm,dsm;
  //down sum to hold how many node still on eventhough current node is off
}seg[40*N+2];
int nw;
void mrge(segment &p,segment &p1,segment &p2,int lo,int hi)
{
  p.dsm=p1.sm+p2.sm;if(p.cnt)p.sm=hi-lo+1;else p.sm=p.dsm;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].cnt+=vl;
    if(seg[node].cnt)seg[node].sm=hi-lo+1;else seg[node].sm=seg[node].dsm;
    return ;
  }
  int md=(lo+hi)/2;
  if(!seg[node].l)seg[node].l=++nw;if(!seg[node].r)seg[node].r=++nw;

  upd(seg[node].l,lo,md,lt,rt,vl);upd(seg[node].r,md+1,hi,lt,rt,vl);
  mrge(seg[node],seg[seg[node].l],seg[seg[node].r],lo,hi);
}
long solve()
{
  int n;cin>>n;vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i]>>bb[i]>>cc[i]>>dd[i];dd[i]--;///
    v.push_back({aa[i],-i});v.push_back({cc[i],i});
  }
  sort(v.begin(),v.end());
  long ans=0;nw=1;memset(seg,0,sizeof(seg));
  int id=-v[0].second;upd(1,-inf,inf,bb[id],dd[id],1);
  for(int i=1;i<v.size();i++)
  {
    id=v[i].second;
    if(id<0)
    {
      id*=-1;ans+=(1LL*seg[1].sm*(v[i].first-v[i-1].first));
      upd(1,-inf,inf,bb[id],dd[id],1);
    }
    else
    {
      ans+=(1LL*seg[1].sm*(v[i].first-v[i-1].first));
      upd(1,-inf,inf,bb[id],dd[id],-1);
    }
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cout<<"Case "<<++tc<<": "<<solve()<<endl;
  }
  return 0;
}