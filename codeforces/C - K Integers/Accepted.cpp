/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2021 21:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 13500 KB                             
*  problem: https://codeforces.com/contest/1268/problem/C
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
using namespace std;
 #include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>Ordered_Set;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5,inf=1e9,mod=998244353;
 struct rangeQuery
{
  long long bit[2][N+2];
  void upd(int x,long long ml,long long sm)
  {
    for( ;x<=N;x+=(x&-x))
      bit[0][x]+=ml,bit[1][x]+=sm;
  }
  long long get(int x)
  {
    long long ml=0,sm=0,bg=x;
    for( ;x>0;x-=(x&-x))
      ml+=bit[0][x],sm+=bit[1][x];
    return ml*bg+sm;
  }
  long long getRange(int lo,int hi)
  {
    return get(hi)-get(lo-1);
  }
  void updRange(int lo,int hi,long long vl)
  {
    upd(lo,vl,-vl*(lo-1));
    upd(hi,-vl,vl*hi);
  }
}a,b;
  int p[N+2];Ordered_Set st;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;p[x]=i;
  }
   long long inv=0;
  for(int i=1;i<=n;i++)
  {
    inv+=b.getRange(p[i],p[i]);st.insert(p[i]);
    a.updRange(p[i],n,1),b.updRange(1,p[i],1);
      int md=(i+1)/2;
    int id=*st.find_by_order(md-1);
    long long ans=inv;
      ans+=a.getRange(1,id)-(1LL*md*(md+1))/2;
    ans+=b.getRange(id+1,n)-(1LL*(i-md)*(i-md+1))/2;
     cout<<ans<<" ";
   }
  cout<<endl;
   return 0;
}