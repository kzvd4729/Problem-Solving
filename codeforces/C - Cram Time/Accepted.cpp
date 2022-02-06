/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2018 14:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1100 KB                              
*  problem: https://codeforces.com/contest/1072/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
vector<long>aa,bb;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long a,b;cin>>a>>b;
  long c=a+b,tt=0;
  for(long i=1; ;i++)
  {
    long sm=(i*(i+1))/2;
    if(sm<=c)tt=i;
    else break;
  }
  for(long i=tt;i>=1;i--)
  {
    if(i<=a)
    {
      a-=i;
      aa.push_back(i);
    }
    else
    {
      b-=i;
      bb.push_back(i);
    }
  }
  sort(aa.begin(),aa.end());
  sort(bb.begin(),bb.end());
  cout<<aa.size()<<endl;
  for(auto x:aa)
    cout<<x<<" ";
  cout<<endl;
  cout<<bb.size()<<endl;
  for(auto x:bb)
    cout<<x<<" ";
  cout<<endl;
   return 0;
}