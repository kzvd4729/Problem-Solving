/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/09/2020 19:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 264 ms                                          memory_used: 15000 KB                             
*  problem: https://codeforces.com/contest/584/problem/E
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
const int N=2e5;
int a[N+2],b[N+2],po[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i],po[b[i]]=i;
   long ans=0;vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)
  {
    //for(int j=1;j<=n;j++)cout<<a[j]<<" --> ";cout<<endl;
    int p=-1;
    for(int j=i;j<=n;j++)
      if(a[j]==b[i])p=j;
    for(int j=p-1;j>=i;j--)
    {
      if(po[a[j]]>=p)
      {
        swap(a[j],a[p]);ans+=p-j;
        v.push_back({j,p});p=j;
        //cout<<i<<" "<<j<<" "<<p<<endl;
      }
    }
    assert(a[i]==b[i]);
  }
  cout<<ans<<endl<<v.size()<<endl;
  for(auto x:v)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}