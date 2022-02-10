/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 6 ms                                            memory_used: 688 KB                               
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
  string tmp;
  do
  {
    if(a.size()<b.size())
      tmp=max(tmp,a);
    if(a.size()<=b.size()&&a<=b&&a[0]!='0')
      tmp=max(tmp,a);
  }while(next_permutation(a.begin(),a.end()));
  if(tmp.size()==0)cout<<-1<<endl;
  else cout<<tmp<<endl;
  return 0;
}