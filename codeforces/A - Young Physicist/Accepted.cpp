/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/14/2018 13:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/69/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
const int N=1e5;
using namespace std;
int n,s1,s2,s3,x,y,z;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x>>y>>z;
    s1+=x;
    s2+=y;
    s3+=z;
  }
  if(s1||s2||s3)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  return 0;
}