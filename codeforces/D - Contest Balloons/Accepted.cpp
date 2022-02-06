/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/13/2018 22:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 826 ms                                          memory_used: 37800 KB                             
*  problem: https://codeforces.com/contest/725/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<long long,long long>,null_type,less<pair<long long,long long> >,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
ordered_set st;
const long long inf=1e18+4;
const long long N=3e5;
long long n,ans=inf;
pair<long long,long long>seg[4*N+2];
struct data
{
  long long bl,wg;
}arr[N+2],lm;
bool cmp(data a,data b)
{
  if(a.bl!=b.bl)return a.bl>b.bl;
  else return a.wg<b.wg;
}
void build(long long node,long long lo,long long hi)
{
  if(lo==hi)
  {
    seg[node]={arr[lo].wg-arr[lo].bl+1,lo};
    return ;
  }
  long long md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
   if(seg[node*2].first<seg[node*2+1].first)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
void upd(long long node,long long lo,long long hi,long long id)
{
  if(lo==hi)
  {
    seg[node]={inf,lo};
    return ;
  }
  long long md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id);
  else upd(node*2+1,md+1,hi,id);
  if(seg[node*2].first<seg[node*2+1].first)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
pair<long long,long long>query(long long node,long long lo,long long hi,long long lt,long long rt)
{
  if(lo>rt||hi<lt)return {inf,1};
  if(lo>=lt&&hi<=rt)return seg[node];
  long long md=(lo+hi)/2;
  pair<long long,long long>p1=query(node*2,lo,md,lt,rt);
  pair<long long,long long>p2=query(node*2+1,md+1,hi,lt,rt);
  if(p1.first<p2.first)return p1;
  else return p2;
}
long long upd_ans(void)
{
  long long sz=st.size();
  long long id=st.order_of_key(make_pair(lm.bl+1,-1));
  ans=min(ans,sz-id+1);
}
long long find_position(void)
{
  long long lo=1,hi=n,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(arr[md].bl>lm.bl)lo=md;
    else hi=md;
  }
  for(md=lo;md<=hi;md++)
    if(arr[md].bl<=lm.bl)return md-1;
  return n;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;--n;
  cin>>lm.bl>>lm.wg;
  for(long long i=1;i<=n;i++)
    cin>>arr[i].bl>>arr[i].wg;
  sort(arr+1,arr+n+1,cmp);
  for(long long i=1;i<=n;i++)
    st.insert(make_pair(arr[i].bl,i));
  build(1,1,n);
  while(true)
  {
    upd_ans();
    if(ans==1)break;
    long long id=find_position();
    pair<long long,long long>p=query(1,1,n,1,id);
    long long nid=p.first;
    if(lm.bl<nid)break;
    lm.bl-=nid;
    upd(1,1,n,p.second);
    st.erase(make_pair(arr[p.second].bl,p.second));
  }
  cout<<ans<<endl;
  return 0;
}