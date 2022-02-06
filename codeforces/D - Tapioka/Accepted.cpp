/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2020 19:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102460/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
bool get(string s)
{
  string d,e,f;
  d="bubble",e="pearl",f="tapioka";
   if(s==d)return true;
  if(s==e)return true;
  if(s==f)return true;
   return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b,c;cin>>a>>b>>c;
   int f=0;
   if(!get(a))cout<<a<<" ",f=1;
  if(!get(b))cout<<b<<" ",f=1;
  if(!get(c))cout<<c<<" ",f=1;
   if(!f)cout<<"nothing";
  cout<<endl;
      return 0;
}