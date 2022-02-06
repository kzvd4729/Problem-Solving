/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2018 21:18                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/962/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,a,b,cnt,print,odd,evv;
string s;
vector<long>v1,v2;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b;
  cin>>s;
  s.push_back('*');
   for(auto x:s)
  {
    if(x=='*')
    {
      if(cnt&1)v1.push_back(cnt);
      else v2.push_back(cnt);
      cnt=0;
    }
    else cnt++;
  }
   for(auto x:v1)
  {
    if(a<b)swap(a,b);
     evv=min(x/2,b);
     odd=min(evv+1,a);
     print+=odd+evv;
    b-=evv;
    a-=odd;
   }
  for(auto x:v2)
  {
    if(a<b)swap(a,b);
     evv=min(x/2,b);
    odd=min(a,min(evv+1,x/2));
     print+=evv+odd;
    b-=evv;
    a-=odd;
   }
  cout<<print<<endl;
   return 0;
}