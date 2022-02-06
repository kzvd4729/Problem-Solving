/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2021 18:22                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 467 ms                                          memory_used: 47800 KB                             
*  problem: https://codeforces.com/contest/1472/problem/E
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
const int N=1e6,inf=1e9,mod=1e9+7;
  int ans[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<vector<int> >a(n),aa(n),bb(n);
    for(int i=0;i<n;i++)
    {
      a[i].resize(3);
      cin>>a[i][0]>>a[i][1];
      a[i][2]=i+1;
    }
    vector<vector<int> >b=a;
     for(int i=0;i<n;i++)swap(b[i][0],b[i][1]);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
     //for(auto x:b)cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
      aa[0]=a[0];
    for(int i=1;i<n;i++)
    {
      aa[i]=aa[i-1];
      if(a[i][1]<aa[i][1])aa[i][1]=a[i][1],aa[i][2]=a[i][2];
    }
     bb[0]=b[0];
    for(int i=1;i<n;i++)
    {
      bb[i]=bb[i-1];
      if(b[i][1]<bb[i][1])bb[i][1]=b[i][1],bb[i][2]=b[i][2];
    }
     for(int i=1;i<=n;i++)ans[i]=-1;
         for(int i=0;i<n;i++)
    {
      vector<int>v={a[i][0],-1,-1};
      int id=lower_bound(a.begin(),a.end(),v)-a.begin();
      id--;
        if(id>=0 && aa[id][1]<a[i][1])ans[a[i][2]]=aa[id][2];
        v={a[i][1],-1,-1};
      id=lower_bound(a.begin(),a.end(),v)-a.begin();
      id--;
       if(id>=0 && aa[id][1]<a[i][0])ans[a[i][2]]=aa[id][2];
        v={a[i][0],-1,-1};
      id=lower_bound(b.begin(),b.end(),v)-b.begin();
      id--;
       if(id>=0 && bb[id][1]<a[i][1])ans[a[i][2]]=bb[id][2];
     }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<'\n';
  }
  return 0;
}