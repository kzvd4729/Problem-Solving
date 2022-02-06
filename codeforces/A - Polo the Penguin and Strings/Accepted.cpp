/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2018 15:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 2900 KB                              
*  problem: https://codeforces.com/contest/288/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
void inv(void)
{
  cout<<-1<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  if(k>n)inv();
  if(k==1&&n>1)inv();
  string fs,ls;
  for(int i=2;i<k;i++)
    ls.push_back(char(i+'a'));
  for(int i=0; ;i++)
  {
    if(i%2==0)fs.push_back('a');
    else fs.push_back('b');
    if(fs.size()+ls.size()==n)
      cout<<fs<<ls<<endl,exit(0);
  }
  return 0;
}