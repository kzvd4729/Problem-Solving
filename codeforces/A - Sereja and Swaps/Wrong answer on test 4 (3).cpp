/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/22/2020 14:58                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/425/problem/A
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
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  int ans=-1e9;
  for(int i=1;i<=n;i++)
  {
    multiset<int>in,ot;int now=0;
    for(int j=1;j<=n;j++)ot.insert(a[j]);
    for(int j=i;j<=n;j++)
    {
      in.insert(a[j]);ot.erase(ot.find(a[j]));
      assert(in.size()+ot.size()==n);
      now+=a[j];ans=max(ans,now);//cout<<now<<endl;
       if(ot.size()==0)continue;int tmp=now;
      auto it=in.begin();auto ti=ot.rbegin();
      int r=min((int)in.size(),(int)ot.size());r=min(r,k);
      for(int l=1;l<=r;l++)
      {
        tmp+=(*ti)-(*it);it++;ti--;
        ans=max(ans,tmp);
      }
    }
  }
  cout<<ans<<endl;
    return 0;
}