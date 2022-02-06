/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/23/2020 18:09                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++14                               
*  run_time: 6000 ms                                         memory_used: 161700 KB                            
*  problem: https://codeforces.com/contest/1093/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
using namespace std;
 #include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>Ordered_Set;
 const int N=2e5,inf=1e9;
int a[N+2],p[N+2],b[N+2],aa[N+2];
 Ordered_Set seg[N*4+8];
void add(int node,int lo,int hi,int id,int vl)
{
  if(vl<0)seg[node].erase(-vl);
  else seg[node].insert(vl);
   if(lo==hi)return;
  int md=(lo+hi)/2;
  if(id<=md)add(node*2,lo,md,id,vl);
  else add(node*2+1,md+1,hi,id,vl);
}
int get(int node,int lo,int hi,int lt,int rt,int a,int b)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].order_of_key(b+1)-seg[node].order_of_key(a);
  int md=(lo+hi)/2;
  return get(node*2,lo,md,lt,rt,a,b)+get(node*2+1,md+1,hi,lt,rt,a,b);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i],p[a[i]]=i;
  for(int i=1;i<=n;i++)
  {
    cin>>b[i];aa[i]=p[b[i]];
    add(1,1,n,i,aa[i]);
  }
  //cout<<"** ";
  //for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<endl;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==2)
    {
      int x,y;cin>>x>>y;swap(b[x],b[y]);
      add(1,1,n,x,-aa[x]);add(1,1,n,y,-aa[y]);
      aa[x]=p[b[x]],aa[y]=p[b[y]];
      add(1,1,n,x,aa[x]);add(1,1,n,y,aa[y]);
    }
    else
    {
      int l,r,a,b;cin>>l>>r>>a>>b;
      cout<<get(1,1,n,a,b,l,r)<<'\n';
    }
  }
  return 0;
}