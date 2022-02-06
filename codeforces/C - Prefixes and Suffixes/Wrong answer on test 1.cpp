/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/18/2018 20:54                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1092/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,nn;
string ss[N+2];
void ck(string s)
{
  for(int i=1;i<=nn;i++)
  {
    int ok=0;
    if(ss[i]==s.substr(0,ss[i].size()))
      ok=1;
    if(ss[i]==s.substr(s.size()-ss[i].size(),ss[i].size()))
      ok=1;
    if(ok==0)return ;
  }
  for(int i=1;i<=nn;i++)
  {
    if(ss[i]==s.substr(0,ss[i].size()))
      cout<<"P";
    else cout<<"S";
  }
  cout<<endl;exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;nn=n+n-2;
  for(int i=1;i<=nn;i++)
    cin>>ss[i];
  for(int i=1;i<=nn;i++)
  {
    for(int j=1;j<=nn;j++)
    {
      if(ss[i].size()==n-1&&ss[j].size()==1)
        ck(ss[i]+ss[j]);
    }
  }
  return 0;
}