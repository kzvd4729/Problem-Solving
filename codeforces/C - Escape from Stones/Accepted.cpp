/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2018 19:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 6000 KB                              
*  problem: https://codeforces.com/contest/265/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,id,arr[N+2];
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  n=s.size();
  id=1;
  for(int i=1;i<=s.size();i++)
  {
    if(s[i-1]=='l')
      arr[n--]=i;
    else arr[id++]=i;
  }
  for(int i=1;i<=s.size();i++)
    cout<<arr[i]<<"\n";
  return 0;
}