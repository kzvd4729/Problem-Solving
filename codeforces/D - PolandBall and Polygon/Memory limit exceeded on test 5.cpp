/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2020 12:25                        
*  solution_verdict: Memory limit exceeded on test 5         language: GNU C++14                               
*  run_time: 2246 ms                                         memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/755/problem/D
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,
rb_tree_tag,tree_order_statistics_node_update>Ordered_Set;
const int N=1e6;
Ordered_Set bit[N+2];
void upd(int id,int x)
{
  for( ;id<=N;id+=id&-id)bit[id].insert(x);
}
int get(int id,int lo,int hi)
{
  int ret=0;
  for( ;id>0;id-=id&-id)
    ret+=bit[id].order_of_key(hi+1)-bit[id].order_of_key(lo);
  return ret;
}
int vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;long long ans=1;
   int p=1;
  while(true)
  {
    if(vs[p])break;vs[p]=1;
    if(p+k>n)
    {
      int now=0,nx=p+k-n;
       now+=(get(p-1,p+1,n)+get(p-1,1,nx-1));
      now-=(get(nx,p+1,n)+get(nx,1,nx-1));now++;
      ans+=now;
       upd(p,nx);upd(nx,p);p=nx;
    }
    else
    {
      int now=0;
      now+=(get(p+k-1,p+k+1,n)+get(p+k-1,1,p-1));
      now-=(get(p,p+k+1,n)+get(p,1,p-1));now++;
      ans+=now;
       upd(p,p+k);upd(p+k,p);p+=k;
     }
    cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}