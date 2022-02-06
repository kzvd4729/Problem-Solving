/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/20/2019 19:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3000 KB                              
*  problem: https://codeforces.com/contest/432/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
 vector<int>zfunction(string s)
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
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();
  vector<int>z=zfunction(s);
   vector<int>fr(n+1);fr[n]++;
  for(int i=1;i<n;i++)
    fr[z[i]]++;
  for(int i=n-1;i>=0;i--)fr[i]+=fr[i+1];
   vector<pair<int,int> >v;
  for(int i=n-1;i>0;i--)
  {
    if(z[i]==n-i)
      v.push_back({n-i,fr[n-i]});
  }
  v.push_back({n,1});
  cout<<v.size()<<endl;
  for(auto x:v)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}