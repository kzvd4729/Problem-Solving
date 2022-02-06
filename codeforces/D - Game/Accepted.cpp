/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 14:59                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/49/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
char a[N+2],b[N+2];
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   int n;
  cin>>n;
  cin>>s;
  for(int i=0;i<n;i++)
  {
    if(i%2)
    {
      a[i]='0';
      b[i]='1';
    }
    else
    {
      a[i]='1';
      b[i]='0';
    }
  }
  int on=0,tw=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]!=a[i])on++;
    if(s[i]!=b[i])tw++;
  }
  cout<<min(on,tw)<<endl;
  return 0;
}