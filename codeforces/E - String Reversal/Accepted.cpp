/****************************************************************************************
*  @author: kzvd4729#                                        created: Mar/24/2021 20:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 7400 KB                              
*  problem: https://codeforces.com/contest/1430/problem/E
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
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5,inf=1e9,mod=998244353;
 set<int>st[26+2];int bit[N+2];
void upd(int id)
{
  for( ;id>0;id-=id&-id)bit[id]++;
}
int get(int id)
{
  int ret=0;
  for( ;id<=N;id+=id&-id)ret+=bit[id];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
  string s;cin>>s;s="#"+s;
   //for(int i=n;i>=1;i--)cout<<s[i];cout<<endl;cout<<endl;
   for(int i=1;i<=n;i++)st[s[i]-'a'+1].insert(i);
   long ans=0;
  for(int i=1;i<=n;i++)
  {
    int c=s[n-i+1]-'a'+1;
    int r=*st[c].begin();st[c].erase(r);
     //cout<<i<<" "<<r+get(r)<<endl;
     ans+=(r+get(r)-i);upd(r);
  }
  cout<<ans<<endl;
  return 0;
}