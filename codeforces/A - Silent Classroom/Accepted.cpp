/****************************************************************************************
*  @author: kzvd4729                                         created: May/18/2019 00:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1166/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<string>v(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
  sort(v.begin(),v.end());
  vector<string>a,b;
  for(int i=0;i<n;i+=2)
    a.push_back(v[i]);
  for(int i=1;i<n;i+=2)
    b.push_back(v[i]);
  int ans=0,cnt=1;
  for(int i=1;i<a.size();i++)
  {
    if(a[i][0]==a[i-1][0])cnt++;
    else
    {
      ans+=(cnt*(cnt-1))/2;
      cnt=1;
    }
  }
  ans+=(cnt*(cnt-1))/2;
  cnt=1;a=b;
  for(int i=1;i<a.size();i++)
  {
    if(a[i][0]==a[i-1][0])cnt++;
    else
    {
      ans+=(cnt*(cnt-1))/2;
      cnt=1;
    }
  }
  ans+=(cnt*(cnt-1))/2;
  cout<<ans<<endl;
  return 0;
}