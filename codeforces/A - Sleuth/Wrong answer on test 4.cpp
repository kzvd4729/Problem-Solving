/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 00:41                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/49/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
string s;
char c;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   getline(cin,s);
  for(auto x:s)
  {
    if(x<'A'||x>'Z')x=x-'a'+'A';
    if(x>='A'&&x<='Z')
      c=x;
  }
  if(c=='A')cout<<"YES"<<endl;
  else if(c=='E')cout<<"YES"<<endl;
  else if(c=='I')cout<<"YES"<<endl;
  else if(c=='O')cout<<"YES"<<endl;
  else if(c=='U')cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}