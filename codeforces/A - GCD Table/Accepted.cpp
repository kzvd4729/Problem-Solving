/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2019 17:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/582/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
map<int,int>fr;
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;
 for(int i=1;i<=n*n;i++)
  cin>>aa[i];
 sort(aa+1,aa+n*n+1,greater<int>());
 vector<int>ans;
 ans.push_back(aa[1]);
 for(int i=2;i<=n*n;i++)
 {
  if(fr[aa[i]]<=0)
  {
   for(auto x:ans)
    fr[__gcd(x,aa[i])]+=2;
   ans.push_back(aa[i]);
  }
  else fr[aa[i]]--;
 }
 if(ans.size()!=n)assert(0);
 for(auto x:ans)
  cout<<x<<" ";
 cout<<endl;
 return 0;
}