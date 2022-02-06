/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/23/2020 19:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 4866 ms                                         memory_used: 74600 KB                             
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
 Ordered_Set bit[N+2];
void add(int id,int vl)
{
  for( ;id<=N;id+=id&-id)bit[id].insert(vl);
}
void err(int id,int vl)
{
  for( ;id<=N;id+=id&-id)bit[id].erase(vl);
}
int get(int id,int a,int b)
{
  int ret=0;
  for( ;id>0;id-=id&-id)
    ret+=bit[id].order_of_key(b+1)-bit[id].order_of_key(a);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i],p[a[i]]=i;
  for(int i=1;i<=n;i++)cin>>b[i],aa[i]=p[b[i]];
  for(int i=1;i<=n;i++)add(i,aa[i]);
  //cout<<"** ";
  //for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<endl;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==2)
    {
      int x,y;cin>>x>>y;swap(b[x],b[y]);
      err(x,aa[x]);err(y,aa[y]);
      aa[x]=p[b[x]],aa[y]=p[b[y]];
      add(x,aa[x]);add(y,aa[y]);
    }
    else
    {
      int l,r,a,b;cin>>l>>r>>a>>b;
      cout<<get(b,l,r)-get(a-1,l,r)<<'\n';
    }
  }
  return 0;
}