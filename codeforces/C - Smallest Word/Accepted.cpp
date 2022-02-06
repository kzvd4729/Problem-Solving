/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/28/2018 22:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1043/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s;cin>>s;int n=s.size();s.push_back('b');
  char f,l;vector<int>pr;
  for(int i=0;i<n;i++)
  {
    f=s[0],l=s[i];
    if(f=='a'&&l=='b')
    {
      if(s[i+1]=='b')
        pr.push_back(0);
      else
      {
        pr.push_back(1);
        reverse(s.begin(),s.begin()+i+1);
      }
    }
    else if(f=='b'&&l=='a')
    {
      if(s[i+1]=='a')
        pr.push_back(0);
      else
      {
        pr.push_back(1);
        reverse(s.begin(),s.begin()+i+1);
      }
    }
    else pr.push_back(0);
   }
  for(int i=0;i<pr.size();i++)
  {
    cout<<pr[i]<<" ";
  }
  cout<<endl;
   return 0;
}