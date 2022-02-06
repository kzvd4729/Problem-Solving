/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/06/2019 13:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/412/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  string s;cin>>s;
  int ds1=k-1,ds2=n-k;
  if(ds1<ds2)
  {
    while(k>1)
    {
      cout<<"LEFT"<<endl;
      k--;
    }
    for(int i=0;i<s.size();i++)
    {
      cout<<"PRINT "<<s[i]<<endl;
      if(i!=s.size()-1)cout<<"RIGHT"<<endl;
    }
  }
  else
  {
    while(k<n)
    {
      cout<<"RIGHT"<<endl;
      k++;
    }
    for(int i=s.size()-1;i>=0;i--)
    {
      cout<<"PRINT "<<s[i]<<endl;
      if(i!=0)cout<<"LEFT"<<endl;
    }
  }
  return 0;
}