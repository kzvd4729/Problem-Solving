/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2021 21:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1487/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 long sq(long x)
{
  long s=sqrt(x+1);
   if(s*s==x)return s;
  s--;
  if(s*s==x)return s;
  s+=2;
  if(s*s==x)return s;
   return inf+1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
     vector<int>v;
  for(long a=3;a<=100000;a++)
  {
    if((a*a-1)%2)continue;
    long b=(a*a-1)/2;
     if(b>inf)break;
     long c=a*a+b*b;
     if(sq(c)<=inf)v.push_back(sq(c));
   }
  sort(v.begin(),v.end());
   //for(int i=0;i<100;i++)cout<<v[i]<<endl;
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    int x=upper_bound(v.begin(),v.end(),n)-v.begin();
    cout<<x<<endl;
  }
    return 0;
}