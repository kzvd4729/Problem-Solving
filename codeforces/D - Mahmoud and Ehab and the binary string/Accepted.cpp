/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/17/2020 19:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/862/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;//cin>>s;
  for(int i=0;i<n;i++)s.push_back('0');
   cout<<"? "<<s<<endl;int x;cin>>x;
  s[0]='1';cout<<"? "<<s<<endl;int y;cin>>y;
   int a,b;
  if(x>y)
  {
    b=1;int lo=1,hi=n,md;
    while(lo<hi)
    {
      md=(lo+hi+1)/2;
      for(int i=1;i<=md;i++)s[i-1]='1';
      for(int i=md+1;i<=n;i++)s[i-1]='0';
       cout<<"? "<<s<<endl;cin>>y;
      if(y==x-md)lo=md;else hi=md-1;
    }
    a=lo+1;
  }
  else
  {
    a=1;int lo=1,hi=n,md;
    while(lo<hi)
    {
      md=(lo+hi+1)/2;
      for(int i=1;i<=md;i++)s[i-1]='1';
      for(int i=md+1;i<=n;i++)s[i-1]='0';
       cout<<"? "<<s<<endl;cin>>y;
      if(y==x+md)lo=md;else hi=md-1;
    }
    b=lo+1;
  }
  cout<<"! "<<a<<" "<<b<<endl;
  return 0;
}