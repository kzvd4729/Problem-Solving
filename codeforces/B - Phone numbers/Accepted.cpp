/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2018 16:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/25/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e2;
int l;
string s;
void case1(void)
{
  for(int i=1;i<=l;i++)
  {
    cout<<s[i-1];
    if(i%2==0&&i!=l)cout<<"-";
  }
  cout<<endl;
}
void case2(void)
{
  cout<<s[0]<<s[1]<<s[2];
  if(l!=3)cout<<"-";
  for(int i=3;i<l;i++)
  {
    cout<<s[i];
    if(i%2==0&&i!=l-1)cout<<"-";
  }
  cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>l;
  cin>>s;
  if(l%2==0)case1();
  else case2();
   return 0;
}