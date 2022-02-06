/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/10/2019 18:12                        
*  solution_verdict: Time limit exceeded on test 1           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1137/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
string s;int f;
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 while(true)
 {
  cout<<"next "<<0<<endl;fflush(stdout);
  int k;cin>>k;
  while(k--)cin>>s;
  cout<<"next "<<0<<" "<<1<<endl;fflush(stdout);
  cin>>k;if(k==2)f=1;
  while(k--)cin>>s;if(f)break;
 }
 f=0;
 while(true)
 {
  cout<<"next ";for(int i=0;i<10;i++)cout<<" "<<i;
  cout<<endl;fflush(stdout);
  int k;cin>>k;if(k==1)f=1;
  while(k--)cin>>s;
 }
 cout<<"done"<<endl;fflush(stdout);
 return 0;
}