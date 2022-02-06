/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2019 17:33                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102215/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;
  int bth=0,up=0,dw=0;
  for(int i=0;i<a.size();i++)
  {
   if(a[i]=='#'&&b[i]=='#')bth++;
   else if(a[i]=='#')up++;
   else if(b[i]=='#')dw++;
  }
  if(!bth&&(up||dw))cout<<"NO\n",exit(0);
   cout<<"YES\n";
  for(int i=0;i<up+bth;i++)
   cout<<"#";
  for(int i=up+bth;i<a.size();i++)
   cout<<".";
   cout<<endl;
   for(int i=0;i<up;i++)
   cout<<".";
  for(int i=up;i<up+bth+dw;i++)
   cout<<"#";
  for(int i=up+bth+dw;i<a.size();i++)
   cout<<".";
  cout<<endl;
   return 0;
}