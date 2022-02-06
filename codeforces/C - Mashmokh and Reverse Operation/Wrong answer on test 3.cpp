/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/22/2020 18:26                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 66500 KB                             
*  problem: https://codeforces.com/contest/414/problem/C
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
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];long a[N+2],b[N+2];
vector<int>seg[4*N+2];
int build(int node,int lo,int hi)
{
  //cout<<node<<" "<<lo<<" "<<hi<<endl;
  if(lo==hi)
  {
    seg[node].push_back(aa[lo]);
    return 0;
  }
  int md=(lo+hi)/2;
  int l=build(node*2,lo,md);build(node*2+1,md+1,hi);
  l++;
   for(auto x:seg[node*2])
    a[l]+=lower_bound(seg[node*2+1].begin(),seg[node*2+1].end(),x)-seg[node*2+1].begin();
  b[l]+=1LL*seg[node*2].size()*seg[node*2+1].size();
   seg[node].resize(seg[node*2].size()+seg[node*2+1].size());
  merge(seg[node*2].begin(),seg[node*2].end(),seg[node*2+1].begin(),seg[node*2+1].end(),seg[node].begin());
   return l;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<(1<<n);i++)cin>>aa[i];
  build(1,0,(1<<n)-1);
   //cout<<seg[2].size()<<" ** "<<seg[3].size()<<endl;
  for(int i=1;i<=n;i++)b[i]-=a[i];
  int q;cin>>q;
  while(q--)
  {
    int x;cin>>x;
    for(int i=1;i<=x;i++)swap(a[i],b[i]);
     long ans=0;
    for(int i=1;i<=n;i++)ans+=a[i];
    cout<<ans<<"\n";
  }
  return 0;
}