/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/10/2020 11:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 5500 KB                              
*  problem: https://codeforces.com/contest/484/problem/B
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
const int N=2e5,R=1e6;
int a[N+2],lw[R+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>v(n);
  for(int i=1;i<=n;i++)cin>>v[i-1];
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  n=v.size();
  for(int i=1;i<=n;i++)a[i]=v[i-1];
  //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  int p=n;lw[R+1]=n+1;
  for(int i=R;i>=1;i--)
  {
    if(a[p]>=i)lw[i]=p--;
    else lw[i]=lw[i+1];
  }
  //for(int i=1;i<=10;i++)cout<<lw[i]<<" ";cout<<endl;
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    ans=max(ans,a[n]%a[i]);
    for(int j=2; ;j++)
    {
      int tr=a[i]*j;if(tr>R)break;
      int id=lw[tr]-1;
      ans=max(ans,a[id]%a[i]);
    }
  }
  cout<<ans<<endl;
  return 0;
}