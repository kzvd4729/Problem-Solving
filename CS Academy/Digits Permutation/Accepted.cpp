/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 12 ms                                           memory_used: 668 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string a,b;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>b;
  sort(a.begin(),a.end());
  if(a.size()>b.size())cout<<-1<<endl,exit(0);
  if(a.size()<b.size())
  {
    reverse(a.begin(),a.end());
    cout<<a<<endl,exit(0);
  }
  string tmp="";
  do
  {
    if(a<=b&&a[0]!='0')
      tmp=max(tmp,a);
  }while(next_permutation(a.begin(),a.end()));
  if(tmp.size()==0)cout<<-1<<endl;
  else cout<<tmp<<endl;
  return 0;
}