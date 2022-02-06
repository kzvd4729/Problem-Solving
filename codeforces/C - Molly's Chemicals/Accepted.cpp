/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/04/2018 16:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1747 ms                                         memory_used: 9400 KB                              
*  problem: https://codeforces.com/contest/776/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long R=1e14;
int n,k;
long ans,arr[N+2];
map<long,int>mp;
void add(long x)
{
  mp.clear();
  mp[0]++;
  for(int i=1;i<=n;i++)
  {
    ans+=mp[arr[i]-x];
    mp[arr[i]]++;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
   vector<long>v;
  v.push_back(1);
   if(k==-1)v.push_back(-1);
   else if(k!=1&&k!=-1)
  {
    long kk=1;
    while(kk<=R)
    {
      kk*=k;
      v.push_back(kk);
    }
  }
   for(int i=1;i<=n;i++)
    arr[i]+=arr[i-1];
  for(auto x:v)
    add(x);
  cout<<ans<<endl;
  return 0;
}