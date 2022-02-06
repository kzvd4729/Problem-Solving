/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/04/2020 18:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 47100 KB                             
*  problem: https://codeforces.com/contest/1284/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s[N+2],t[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
   for(int i=1;i<=n;i++)cin>>s[i];
  for(int i=1;i<=m;i++)cin>>t[i];
   int lcm=n*m/__gcd(n,m);
  int a=1,b=1;
  vector<string>v;
  for(int i=1;i<=lcm;i++)
  {
    v.push_back(s[a]+t[b]);
    a++,b++;if(a>n)a=1;if(b>m)b=1;
  }
  int q;cin>>q;
  while(q--)
  {
    int x;cin>>x;x--;
    x%=lcm;cout<<v[x]<<"\n";
  }
  return 0;
}