/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2018 22:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 5700 KB                              
*  problem: https://codeforces.com/contest/962/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,a,b,cnt,print,odd,evv;
string s;
vector<int>v;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b;
  cin>>s;
  s.push_back('*');
  cnt=0;
  for(auto x:s)
  {
    if(x=='*')
    {
      v.push_back(cnt);
      cnt=0;
    }
    else cnt++;
  }
  for(auto x:v)
  {
    if(a<b)swap(a,b);
    odd=min((x+1)/2,a);
    evv=min(x/2,b);
     print+=odd+evv;
    a-=odd;
    b-=evv;
  }
  cout<<print<<endl;
   return 0;
}