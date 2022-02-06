/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/18/2020 12:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 176300 KB                            
*  problem: https://codeforces.com/contest/526/problem/D
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
const long N=3e6;
vector<long> z_function(string s) {
    long n = (long) s.length();
    vector<long> z(n);
    for (long i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
long ln[N+2],ad[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;cin>>n>>k;string s;cin>>s;
  if(k>n)
  {
    for(long i=1;i<=n;i++)cout<<0;
      cout<<endl,exit(0);
  }
  vector<long>z=z_function(s);
  for(long i=1;i<=2*N;i++)z.push_back(0);
  //for(long i=0;i<n;i++)cout<<z[i]<<" ";cout<<endl;
   for(long l=1;l<=n;l++)
  {
    if(l*k>n)continue;ln[l]=1;
    for(long i=l;i<k*l;i+=l)
    {
      if(z[i]<l)ln[l]=0;
    }
    if(ln[l]==0)continue;
    ad[k*l-1]++,ad[k*l]--;long mn=0;
    if(k*l<n)mn=min(l,z[k*l]);
    ad[k*l]++;
    if(k*l+mn<n)ad[k*l+mn]--;
  }
  for(long i=0;i<n;i++)
  {
    if(i)ad[i]+=ad[i-1];if(ad[i]<0)exit(0);
    cout<<(bool)ad[i];
  }
  cout<<endl;
  //for(long i=1;i<=n;i++)cout<<ln[i]<<" ";cout<<endl;
  return 0;
}