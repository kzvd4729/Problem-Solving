/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/18/2020 12:20                        
*  solution_verdict: Runtime error on test 37                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 40200 KB                             
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
const int N=2e6;
vector<int>zFunction(string s)
{
  int n=s.size();vector<int>z(n);
  z[0]=0;//l,r maintains a window with maximum r
  for(int i=1,l=0,r=0;i<n;i++)
  {
    if(i<=r)z[i]=min(r-i+1,z[i-l]);//inside the window
    while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;//brute-force
    if(i+z[i]-1>r)l=i,r=i+z[i]-1;//r update
  }
  return z;
}
int ln[N+2],ad[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;string s;cin>>s;
  if(k>n)
  {
    for(int i=1;i<=n;i++)cout<<0;
      cout<<endl,exit(0);
  }
  vector<int>z=zFunction(s);
  for(int i=1;i<=N;i++)z.push_back(0);
  //for(int i=0;i<n;i++)cout<<z[i]<<" ";cout<<endl;
   for(int l=1;l<=n;l++)
  {
    if(l*k>n)continue;ln[l]=1;
    for(int i=l;i<k*l;i+=l)
    {
      if(z[i]<l)ln[l]=0;
    }
    if(ln[l]==0)continue;
    ad[k*l-1]++,ad[k*l]--;int mn=0;
    if(k*l<n)mn=min(l,z[k*l]);
    ad[k*l]++,ad[k*l+mn]--;
  }
  for(int i=0;i<n;i++)
  {
    if(i)ad[i]+=ad[i-1];
    cout<<(bool)ad[i];
  }
  cout<<endl;
  //for(int i=1;i<=n;i++)cout<<ln[i]<<" ";cout<<endl;
  return 0;
}