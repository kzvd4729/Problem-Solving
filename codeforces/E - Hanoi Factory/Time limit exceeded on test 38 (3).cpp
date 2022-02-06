/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2020 13:39                        
*  solution_verdict: Time limit exceeded on test 38          language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 154600 KB                            
*  problem: https://codeforces.com/contest/777/problem/E
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
#include<chrono>
#include<ext/pb_ds/assoc_container.hpp>
#define long long long
using namespace std;
using namespace __gnu_pbds;
const int N=1e5,R=1e9;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
string s[N+2];gp_hash_table<int,long,chash>bit;
void upd(int x,long vl)
{
  for( ;x<=R;x+=x&-x)bit[x]=max(bit[x],vl);
}
long get(int x)
{
  long ret=0;
  for( ;x>0;x-=x&-x)ret=max(ret,bit[x]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<vector<int> >v(n);
  for(int i=0;i<n;i++)
  {
    v[i].resize(3);cin>>v[i][0]>>v[i][1]>>v[i][2];
  }
  sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
    if(a[1]==b[1])return a[0]>b[0];
    return a[1]>b[1];
  });
  long ans=0;
  for(int i=0;i<n;i++)
  {
    long now=get(v[i][1]-1)+v[i][2];
    ans=max(ans,now);upd(v[i][0],now);
  }
  cout<<ans<<endl;
  return 0;
}