/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/21/2020 21:14                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 13900 KB                             
*  problem: https://codeforces.com/contest/1381/problem/A2
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
string aa,bb;
int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n>>aa>>bb;
    for(int i=0;i<n;i++)a[i]=aa[i]-'0',b[i]=bb[i]-'0';
    vector<int>ans;int l=0,r=n-1,rv=0;
    for(int i=n-1;i>0;i--)
    {
      int ed=r,bg=l;if(rv)swap(bg,ed);
       //cout<<bg<<" "<<ed<<endl;
       if(a[ed]^rv==b[i])
      {
        if(rv)l++;else r--;
        continue;
      }
       if(a[bg]^rv==b[i])
      {
        ans.push_back(1);a[bg]^=1;
      }
      rv^=1;
      if(rv)l++;else r--;
      ans.push_back(i+1);
    }
    if(a[l]^rv!=b[0])ans.push_back(1);
    cout<<ans.size()<<" ";
    for(auto x:ans)cout<<x<<" ";
      cout<<endl;
  }
  return 0;
}