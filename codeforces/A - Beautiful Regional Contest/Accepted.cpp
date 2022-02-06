/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2020 14:51                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 218 ms                                          memory_used: 26300 KB                             
*  problem: https://codeforces.com/contest/1264/problem/A
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
void compress(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(a[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
   for(int i=1;i<=n;i++)a[i]=mp[a[i]];
}
int fr[N+2];
void solve()
{
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  compress(n);
  int mx=a[1];
    for(int i=1;i<=mx;i++)fr[i]=0;
  for(int i=1;i<=n;i++)fr[a[i]]++;
  int av=0;
  for(int i=mx;i>=1;i--)
  {
    //cout<<fr[i]<<" ";
    if(av+fr[i]<=n/2)av+=fr[i];
    else break;
  }
  int cnt=0;
  for(int i=mx-1;i>=1;i--)
  {
    cnt+=fr[i];//cout<<cnt<<endl;
    if(cnt>fr[mx]&&av-cnt-fr[mx]>fr[mx])
    {
      cout<<fr[mx]<<" "<<cnt<<" "<<av-cnt-fr[mx]<<'\n';
      return;
    }
  }
  cout<<"0 0 0\n";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve(); 
  }
  return 0;
}