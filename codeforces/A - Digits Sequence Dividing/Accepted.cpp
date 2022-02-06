/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/28/2019 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1107/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;string s;cin>>s;
    string a,b;a.push_back(s[0]);
    for(int i=1;i<n;i++)b.push_back(s[i]);
     if(n==2&&b<=a)
      cout<<"NO"<<endl;
    else
    {
      cout<<"YES"<<endl;
      cout<<2<<endl;
      cout<<a<<" "<<b<<endl;
    }
   }
  return 0;
}