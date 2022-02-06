/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2018 21:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4800 KB                              
*  problem: https://codeforces.com/contest/962/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e14;
long mn=inf;
vector<long>v,sq;
string s;
long match(long x)
{
  v.clear();
  while(x)
  {
    v.push_back(x%10);
    x/=10;
  }
  reverse(v.begin(),v.end());
  long i=0,cnt=0;
  for(auto z:v)
  {
    for( ;i<s.size();i++)
    {
      if(z==(long)(s[i]-'0'))
      {
        cnt++;
        i++;
        break;
      }
    }
  }
  if(cnt==v.size())return s.size()-v.size();
  else return inf;
 }
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
   for(long i=1;i<=100000LL;i++)sq.push_back(i*i);
  for(auto x:sq)mn=min(mn,match(x));
  if(mn==inf)mn=-1;
  cout<<mn<<endl;
  return 0;
}