/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2021 01:15                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 26200 KB                             
*  problem: https://codeforces.com/contest/1520/problem/F1
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
//#define long long long
using namespace std;
 #include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>Ordered_Set;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5,inf=1e9,mod=1e9+7;
 Ordered_Set bit[N+2];
 void insert(int id,int x)
{
  for( ;id>=1;id-=id&-id)bit[id].insert(x);
}
int get(int id,int l,int r)
{
  int ret=0;
  for( ;id<=N;id+=id&-id)
    ret+=bit[id].order_of_key(r+1)-bit[id].order_of_key(l);
   return ret;
}
   //interactor
string s="000000";
 int askSystem(int lo,int hi)
{
  int ret;
  cout<<"? "<<lo<<" "<<hi<<endl;
  cin>>ret;
   return ret;
    ret=0;
  for(int i=lo-1;i<hi;i++)ret+=s[i]-'0';
   return ret;
}
void systemPrint(int x)
{
  cout<<"! "<<x<<endl;
  //s[x-1]='1';
}
    pair<int,int>dp[4*N+2];int tim;
int ask(int nd,int lo,int hi,int pr)
{
  if(dp[nd]==make_pair(0,0))
  {
    int x=askSystem(lo,hi);
     //cout<<lo<<" "<<hi<<" "<<x<<endl;
     dp[nd]={tim,x};
    // if(nd!=1)
    // {
    //   if(nd%2==0)dp[nd+1]={tim,pr-x};
    //   else dp[nd-1]={tim,pr-x};
    // }
    return x;
  }
  else
  {
    return dp[nd].second+get(dp[nd].first,lo,hi);
  }
}
 void dfs(int nd,int lo,int hi,int pr,int k)
{
  if(lo==hi)
  {
    systemPrint(lo);
    insert(tim,lo);return ;
  }
  int md=(lo+hi)/2;
   int zr=md-lo+1-ask(nd*2,lo,md,pr);
  if(zr>=k)return dfs(nd*2,lo,md,md-lo+1-zr,k);
  else return dfs(nd*2+1,md+1,hi,md-lo+1-zr,k-zr);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,t;cin>>n>>t;
   for(tim=1;tim<=t;tim++)
  {
    int k;cin>>k;
    dfs(1,1,n,ask(1,1,n,0),k);
  }
    return 0;
}